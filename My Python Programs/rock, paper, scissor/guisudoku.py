import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QGridLayout, QLineEdit, QPushButton

class SudokuUI(QMainWindow):
    def __init__(self):
        super().__init__()

        # Set window properties
        self.setWindowTitle("Sudoku")
        self.setGeometry(100, 100, 450, 450)

        # Create grid layout and add line edits
        self.grid = QGridLayout()
        self.cells = []
        for i in range(9):
            row = []
            for j in range(9):
                cell = QLineEdit()
                cell.setFixedSize(50, 50)
                cell.setAlignment(Qt.AlignCenter)
                cell.setFont(QFont("Arial", 20))
                self.grid.addWidget(cell, i, j)
                row.append(cell)
            self.cells.append(row)

        # Add solve button
        self.solve_button = QPushButton("Solve")
        self.solve_button.clicked.connect(self.solve)
        self.grid.addWidget(self.solve_button, 9, 0, 1, 9)

        # Set central widget and layout
        self.central_widget = QWidget()
        self.central_widget.setLayout(self.grid)
        self.setCentralWidget(self.central_widget)

    def solve(self):
        # Get puzzle
        puzzle = []
        for row in self.cells:
            puzzle_row = []
            for cell in row:
                value = cell.text()
                if value:
                    puzzle_row.append(int(value))
                else:
                    puzzle_row.append(0)
            puzzle.append(puzzle_row)
        
        # Solve puzzle
        solution = solve(puzzle)

        # Update cells with solution
        if solution:
            for i in range(9):
                for j in range(9):
                    self.cells[i][j].setText(str(solution[i][j]))
        else:
            QMessageBox.warning(self, "Sudoku", "This puzzle has no solution.")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = SudokuUI()
    window.show()
    sys.exit(app.exec_())
