markdown file thing
![Board Game Cafe Logo](https://png.pngtree.com/png-clipart/20220206/original/pngtree-coffee-and-cafe-brand-logo-design-using-a-glass-cup-concept-png-image_7264043.png)

This program is designed to help manage board games for a board game café. Keeps track of what games are available, how many copies exist, and which customers have borrowed them. The system can check out games to customers, track when they’re returned, and store basic info about who has what and when it’s due back. 

Nouns:
what type of boardGame
what is checkedOut
Title of thing
TotalCopies i have (stock purpose)
AvailableCopies
Customer Name
ID
DueDate

Verbs:
is it checkOut 
is it returnGame
isAvailable
manage lending(keeping track)
track borrowed items

mermaid
```mermaid
classDiagram

class BoardGame {
+string title
+int totalCopies
+int availableCopies
+BoardGame(string title, int copies)
+bool avaliable()
+void checkOut()
+void returnGame()
}
BoardGame --> AvailabilityCheck : check available?
AvailabilityCheck ..> BoardGame : returns answer

AvailabilityCheck --> Customer : if yes


class Customer {
+string name
+int customersID
+Customer(string name, int id)
}

DueDateNote --> CheckedOut : checking out

class CheckedOut {
+BoardGame* BoardGame
+Customer* customer
+string dueDate
+CheckedOut(BoardGame* BoardGame, Customer* customer, string dueDate)
}


class AvailabilityCheck {
+bool available()
}

Customer --> DueDateNote : issue due date

class DueDateNote {
+string dueDate
}

```

