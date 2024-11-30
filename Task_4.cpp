#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;

    Task(const std::string& desc) : description(desc), isCompleted(false) {}
};

void display_Menu() {
    std::cout << "\n=== TO-DO LIST MANAGER ===\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void addTask(std::vector<Task>& tasks) {
    std::cout << "Enter task description: ";
    std::string discrip;
    std::getline(std::cin, discrip);
    tasks.emplace_back(discrip);
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task>& tas_ks) {
    if (tas_ks.empty()) {
        std::cout << "No tasks to display.\n";
        return;
    }

    std::cout << "\n--- Your Tasks ---\n";
    for (size_t i = 0; i < tas_ks.size(); ++i) {
        std::cout << i + 1 << ". " << tas_ks[i].description
                  << " [" << (tas_ks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

void mark_Task_Completed(std::vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    std::cout << "Enter task number to mark as completed: ";
    size_t taskNumber;
    std::cin >> taskNumber;
    std::cin.ignore(); // Ignore leftover newline character

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    std::cout << "Enter task number to remove: ";
    size_t task_Number;
    std::cin >> task_Number;
    std::cin.ignore(); // Ignore leftover newline character

    if (task_Number >= 1 && task_Number <= tasks.size()) {
        tasks.erase(tasks.begin() + task_Number - 1);
        std::cout << "Task removed successfully.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int cho_ice;

    do {
        display_Menu();
        std::cin >> cho_ice;
        std::cin.ignore(); // Ignore leftover newline character

        switch (cho_ice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                mark_Task_Completed(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (cho_ice != 5);

    return 0;
}
