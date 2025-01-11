#include <iostream>
#include <string>
using namespace std;

// Subsystem components
class AudioPlayer {
  public:
    void playAudio(string filename) {
      cout << "Playing audio file: " + filename;
    }
};

class VideoPlayer {
  public:
    void playVideo(string filename) {
      cout << "Playing video file: " + filename;
    }
};

class ImageLoader {
  public:
    void loadImage(string filename) {
      cout << "Loading image file: " + filename;
    }
};

// Facade class
class MultimediaFacade {
  private:
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;
    ImageLoader imageLoader;

  public:
    void playMedia(string filename, string mediaType) {
      if (mediaType.compare("audio") == 0) {
        audioPlayer.playAudio(filename);
      } else if (mediaType.compare("video") == 0) {
        videoPlayer.playVideo(filename);
      } else if (mediaType.compare("image") == 0) {
        imageLoader.loadImage(filename);
      } else {
        cout << "Unsupported media type: " + mediaType;
      }
    }
};

// Client code using the facade
int main() {
  MultimediaFacade facade;

  // Playing audio
  facade.playMedia("song.mp3", "audio");

  // Playing video
  facade.playMedia("movie.mp4", "video");

  // Loading image
  facade.playMedia("picture.jpg", "image");

  // Unsupported media type
  facade.playMedia("unknown.file", "unknown");

  return 0;
}


/* 
Output

Playing audio file: song.mp3
Playing video file: movie.mp4
Loading image file: picture.jpg
Unsupported media type: unknown
*/