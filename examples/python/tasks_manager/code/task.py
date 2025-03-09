class Task:
    def __init__(self, description, priority, completed=False):
        self.description = description
        self.priority = priority
        self.completed = completed

    def mark_completed(self):
        self.completed = True

    def __str__(self):
        return (
            f"[{'X' if self.completed else ' '}] {self.description} ({self.priority})"
        )
