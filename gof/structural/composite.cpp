// CPP program to illustrate
// Composite design pattern
#include <iostream>
#include <vector>
using namespace std;

// Component
class Task {
  public:
    string title;
    virtual void display() = 0;
};

// Leaf
class SimpleTask : public Task {
  public:
    SimpleTask(string t) {
      title = t;
    }

    void display() {
      cout << "Simple Task: " + title << "\n";
    }
};

// Composite
class TaskList : public Task {
  private:
    vector<Task* > tasks;

  public:
    TaskList(string t) {
      title = t;
    }

    void display() {
      cout << "Task List: " + title << "\n";

      for (Task* task : tasks) {
        task->display();
      }
    }

    void addTask(Task* t) {
      tasks.push_back(t);
    }
};

// Client
int main() {
  // Creating simple tasks
  Task* simpleTask1 = new SimpleTask("Complete Coding");
  Task* simpleTask2 = new SimpleTask("Write Documentation");
  Task* simpleTask3 = new SimpleTask("Design");
  Task* simpleTask4 = new SimpleTask("Implementation");

  // Creating a task list
  TaskList projectTasks("Project Tasks");
  projectTasks.addTask(simpleTask1);
  projectTasks.addTask(simpleTask2);

  // Nested task list
  TaskList* phase1Tasks = new TaskList("Phase 1 Tasks");
  phase1Tasks->addTask(simpleTask3);
  phase1Tasks->addTask(simpleTask4);

  // add nested list to root
  projectTasks.addTask(phase1Tasks);

  // Displaying tasks
  projectTasks.display();

  return 0;
}


/*
Output

Task List: Project Tasks
  Simple Task: Complete Coding
  Simple Task: Write Documentation
  Task List: Phase 1 Tasks
    Simple Task: Design
    Simple Task: Implementation
*/