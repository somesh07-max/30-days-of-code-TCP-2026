
const cells = document.querySelectorAll(".cell");
const statusText = document.getElementById("status");
const restartBtn = document.getElementById("restart");
const confetti = document.getElementById("confetti");


let currentPlayer = "X";      // X always starts
let gameRunning = true;       // Check if game is active
let board = ["", "", "", "", "", "", "", "", ""];


const winConditions = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6]
];


cells.forEach((cell, index) => {
    cell.addEventListener("click", () => cellClicked(cell, index));
});


function cellClicked(cell, index) {

    
    if (board[index] !== "" || !gameRunning) {
        return;
    }

   
    board[index] = currentPlayer;
    cell.textContent = currentPlayer;

    
    if (checkWinner()) {
        statusText.textContent = "🎉 Player " + currentPlayer + " Wins!";
        gameRunning = false;
        confetti.classList.add("show");
        return;
    }

    // Check draw
    if (isDraw()) {
        statusText.textContent = "😐 Match Draw!";
        gameRunning = false;
        return;
    }

    // Change player turn
    currentPlayer = currentPlayer === "X" ? "O" : "X";
    statusText.textContent = "Player " + currentPlayer + "'s turn";
}
function checkWinner() {
    for (let i = 0; i < winConditions.length; i++) {

        let condition = winConditions[i];
        let a = condition[0];
        let b = condition[1];
        let c = condition[2];

        if (
            board[a] !== "" &&
            board[a] === board[b] &&
            board[b] === board[c]
        ) {
            // Highlight winning cells
            cells[a].classList.add("win");
            cells[b].classList.add("win");
            cells[c].classList.add("win");
            return true;
        }
    }
    return false;
}


function isDraw() {
    for (let i = 0; i < board.length; i++) {
        if (board[i] === "") {
            return false;
        }
    }
    return true;
}


restartBtn.addEventListener("click", restartGame);

function restartGame() {
    board = ["", "", "", "", "", "", "", "", ""];
    gameRunning = true;
    currentPlayer = "X";
    statusText.textContent = "Player X's turn";
    confetti.classList.remove("show");

    cells.forEach(cell => {
        cell.textContent = "";
        cell.classList.remove("win");
    });
}
