#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Memento
class DocumentMemento {
  private:
    string content;

  public:
    DocumentMemento(const string& originatorState) : content(originatorState) {}

    string GetSavedState() const {
      return content;
    }
};

// Originator
class Document {
  private:
    string content;
  
  public:
    void write(const string& newContent) {
      content = newContent;
    }
  
    string getContent() const {
      return content;
    }
  
    // Create a DocumentMemento object to save the current content.
    DocumentMemento CreateMemento() const {
      return DocumentMemento(content);
    }
  
    // Restore the content from a DocumentMemento object.
    void RestoreState(const DocumentMemento& documentMemento) {
      content = documentMemento.GetSavedState();
    }
};
 
// Caretaker
class History {
  private:
    vector<DocumentMemento> mementos;
  
  public:
    void AddMemento(const DocumentMemento& documentMemento) {
      mementos.push_back(documentMemento);
    }
  
    DocumentMemento GetMemento(int index) const {
      if (index >= 0 && index < mementos.size()) {
        return mementos[index];
      }
      
      throw out_of_range("Invalid DocumentMemento index");
    }
};
 
int main() {
  Document document;
  History history;
 
  document.write("hello");
  history.AddMemento(document.CreateMemento());
 
  document.write(" world");
  history.AddMemento(document.CreateMemento());

  document.write(" and c++");
  history.AddMemento(document.CreateMemento());
 
  // Restore to the previous content
  document.RestoreState(history.GetMemento(1));
  cout << "Current content: " << document.getContent() << endl;
 
  return 0;
}


/*
Output

Current content: hello world
*/