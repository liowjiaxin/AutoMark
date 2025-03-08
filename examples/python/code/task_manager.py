import json
from task import Task


class TaskManager:
    def __init__(self, filename="tasks.json"):
        self.filename = filename
        self.tasks = self.load_tasks()

    def add_task(self, description, priority):
        self.tasks.append(Task(description, priority))
        self.save_tasks()

    def view_tasks(self, priority_filter=None):
        if not self.tasks:
            print("No tasks found.")
            return

        for i, task in enumerate(self.tasks):
            if (
                priority_filter == ""
                or task.priority.lower() == priority_filter.lower()
            ):
                print(f"{i + 1}. {task}")

    def mark_task_completed(self, index):
        if 1 <= index <= len(self.tasks):
            self.tasks[index - 1].mark_completed()
            self.save_tasks()
        else:
            print("Invalid task index.")

    def view_completed_tasks(self):
        completed_tasks = [task for task in self.tasks if task.completed]
        if not completed_tasks:
            print("No completed tasks.")
            return

        for i, task in enumerate(completed_tasks):
            print(f"{i + 1}. {task}")

    def save_tasks(self):
        data = [
            {
                "description": task.description,
                "priority": task.priority,
                "completed": task.completed,
            }
            for task in self.tasks
        ]
        with open(self.filename, "w") as f:
            json.dump(data, f)

    def load_tasks(self):
        try:
            with open(self.filename, "r") as f:
                data = json.load(f)
            return [
                Task(task["description"], task["priority"], task["completed"])
                for task in data
            ]
        except FileNotFoundError:
            return []
        except json.JSONDecodeError:
            return []
