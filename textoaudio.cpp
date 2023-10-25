#include <iostream>
#include <fstream>
#include <string>

#include "google/cloud/text_to_speech/v1beta1/text_to_speech.grpc.pb.h"
#include "google/cloud/text_to_speech/v1beta1/text_to_speech.pb.h"
#include <grpcpp/grpcpp.h>

using google::cloud::texttospeech::v1beta1::AudioConfig;
using google::cloud::texttospeech::v1beta1::AudioEncoding;
using google::cloud::texttospeech::v1beta1::SynthesisInput;
using google::cloud::texttospeech::v1beta1::TextToSpeech;
using google::cloud::texttospeech::v1beta1::VoiceSelectionParams;
using google::protobuf::Duration;

void SynthesizeText(const std::string& text,
                    const std::string& output_file,
                    const std::string& language_code = "en-US",
                    const std::string& voice_name = "en-US-Wavenet-D") {
  // Create a TextToSpeech object.
  TextToSpeech::Stub stub(
      grpc::CreateChannel("texttospeech.googleapis.com", grpc::SslCredentials(grpc::SslCredentialsOptions())));
  SynthesisInput input;
  input.set_text(text);

  VoiceSelectionParams voice_selection_params;
  voice_selection_params.set_language_code(language_code);
  voice_selection_params.set_name(voice_name);

  AudioConfig audio_config;
  audio_config.set_audio_encoding(AudioEncoding::MP3);
  audio_config.mutable speaking_rate()->set_value(0.9);
  audio_config.mutable pitch()->set_value(-2.0);
  audio_config.mutable volume_gain_db()->set_value(3.0);
  audio_config.mutable sample_rate_hertz()->set_value(44100);

  Duration duration;
  duration.set_seconds(10);

  // Perform the text-to-speech request on the text input with the selected
  // voice parameters and audio file type.
  google::cloud::texttospeech::v1beta1::SynthesizeSpeechRequest request;
  *request.mutable_input() = input;
  *request.mutable_voice() = voice_selection_params;
  *request.mutable_audio_config() = audio_config;
  *request.mutable_timepoints() = duration;

  // Send the request and receive the response.
  grpc::ClientContext context;
  google::cloud::texttospeech::v1beta1::SynthesizeSpeechResponse response;
  grpc::Status status = stub.SynthesizeSpeech(&context, request, &response);

  if (status.ok()) {
    // Write the binary audio content to a file.
    std::ofstream output(output_file, std::ios_base::binary);
    output << response.audio_content();
    output.close();
    std::cout << "Audio content written to file: " << output_file << std::endl;
  } else {
    std::cerr << "Failed to synthesize speech: " << status.error_message()
              << std::endl;
    return;
  }
}

int main(int argc, char** argv) {
    SynthesizeText("Hello World!", "output.mp3");
    return EXIT_SUCCESS;
}
