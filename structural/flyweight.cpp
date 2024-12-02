#include <iostream>
#include <unordered_map>
using namespace std;

// Flyweight Interface
class CharacterFlyweight {
  public:
    virtual void draw(int extrinsicState) = 0;
};

// Concrete Flyweight
class Character : public CharacterFlyweight {
  private:
    char m_intrinsicState;
  
  public:
    Character(char intrinsicState) : m_intrinsicState(intrinsicState) {}

    void draw(int extrinsicState) {
      cout << "Drawing character '" << m_intrinsicState << "' at position " << extrinsicState << endl;
    }
};

// Flyweight factory
class CharacterFactory {
  private:
    // Flyweight objects
    unordered_map<char, Character* > charCache;

  public:
    Character* getCharacter(char key) {
      if (charCache.find(key) == charCache.end()) {
        charCache[key] = new Character(key);
      }
      
      return charCache[key];
    }
};

// Client
int main() {
  CharacterFactory characterFactory;

  // Drawing characters 'A', 'B', 'C' at different positions
  characterFactory.getCharacter('A')->draw(0);
  characterFactory.getCharacter('A')->draw(1);
  characterFactory.getCharacter('B')->draw(2);

  return 0;
}

/*
Output

Drawing character 'A' at position 0
Drawing character 'A' at position 1
Drawing character 'B' at position 2
*/