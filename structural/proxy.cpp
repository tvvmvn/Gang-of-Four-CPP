#include <iostream>
#include <string>
using namespace std;

// Subject
class Image {
  public:
    virtual void display() = 0;
};

// Real Subject
class RealImage : public Image {
  private:
    string filename;

  public:
    RealImage(const string &filename) : filename(filename) {
      // Simulate creating the image.
      // This can be a resource-intensive operation.
      cout << "Created image: " << filename << endl;
    }

    void display() override {
      cout << "Displaying image: " << filename << endl;
    }
};

// Proxy
class ImageProxy : public Image {
  private:
    RealImage* realImage; // Reference to the Real Object
    string filename;

  public:
    ImageProxy(const string &filename) : filename(filename), realImage(nullptr) {}

    void display() override {
      // The proxy creates real image when it's necessary
      if (realImage == nullptr) {
        realImage = new RealImage(filename);
      }

      // Some tasks for authencation, validation in here..

      realImage->display();
    }
};

// Client
int main() {
  // Create a proxy to an image
  Image* image = new ImageProxy("example.jpg");

  // Image will be created only when display() is called
  image->display();

  // Image will not be created again, as it has been cached in the Proxy
  image->display();

  // Clean up
  delete image; 

  return 0;
}

/*
Output

Loading image: example.jpg
Displaying image: example.jpg
Displaying image: example.jpg
*/