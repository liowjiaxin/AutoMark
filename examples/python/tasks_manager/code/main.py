from task_manager import TaskManager


def main():
    task_manager = TaskManager()

    while True:
        print("\nTask Manager")
        print("1. Add Task")
        print("2. View Tasks")
        print("3. Mark Task Completed")
        print("4. View Completed Tasks")
        print("5. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            description = input("Enter task description: ")
            priority = input("Enter priority (High/Medium/Low): ")
            task_manager.add_task(description, priority)
        elif choice == "2":
            priority_filter = input("Enter priority filter (optional): ")
            task_manager.view_tasks(priority_filter)
        elif choice == "3":
            try:
                index = int(input("Enter task index to mark completed: "))
                task_manager.mark_task_completed(index)
            except ValueError:
                print("Invalid input. Please enter a number.")
        elif choice == "4":
            task_manager.view_completed_tasks()
        elif choice == "5":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
