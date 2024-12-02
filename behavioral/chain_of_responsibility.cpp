#include <iostream>
#include <string>
using namespace std;

// Handler Interface
class AuthenticationHandler {
  public:
    virtual void setNextHandler(AuthenticationHandler* handler) = 0;
    virtual void handleRequest(const string& request) = 0;
};

// Concrete Handler
class UsernamePasswordHandler : public AuthenticationHandler {
  private:
    AuthenticationHandler* nextHandler;

  public:
    void setNextHandler(AuthenticationHandler* handler) override {
      nextHandler = handler;
    }

    void handleRequest(const string& request) override {
      if (request == "username_password") {
        cout << "Authenticated using username and password." << endl;
      } else if (nextHandler != nullptr) {
        nextHandler->handleRequest(request);
      } else {
        cout << "Invalid authentication method." << endl;
      }
    }
};

// Concrete Handler
class OAuthHandler : public AuthenticationHandler {
  private:
    AuthenticationHandler* nextHandler;

  public:
    void setNextHandler(AuthenticationHandler* handler) override {
      nextHandler = handler;
    }

    void handleRequest(const string& request) override {
      if (request == "oauth_token") {
        cout << "Authenticated using OAuth token." << endl;
      } else if (nextHandler != nullptr) {
        nextHandler->handleRequest(request);
      } else {
        cout << "Invalid authentication method." << endl;
      }
    }
};

// Client
int main() {
  AuthenticationHandler* usernamePasswordHandler = new UsernamePasswordHandler();
  AuthenticationHandler* oauthHandler = new OAuthHandler();

  // Set up the chain
  usernamePasswordHandler->setNextHandler(oauthHandler);

  // Handling authentication requests
  usernamePasswordHandler->handleRequest("oauth_token");
  usernamePasswordHandler->handleRequest("username_password");

  delete usernamePasswordHandler;
  delete oauthHandler;

  return 0;
}


/*
Output

Authenticated using OAuth token.
Authenticated using username and password.
Invalid authentication method.
*/