let currentPlayer = 'X';
const board = [
    ['', '', ''],
    ['', '', ''],
    ['', '', '']
];

const cells = document.querySelectorAll('.cell');
const status = document.getElementById('status');

const checkWinner = () => {
    // Check rows and columns
    for (let i = 0; i < 3; i++) {
        if (board[i][0] === currentPlayer && board[i][1] === currentPlayer && board[i][2] === currentPlayer) {
            return true;
        }
        if (board[0][i] === currentPlayer && board[1][i] === currentPlayer && board[2][i] === currentPlayer) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] === currentPlayer && board[1][1] === currentPlayer && board[2][2] === currentPlayer) {
        return true;
    }
    if (board[0][2] === currentPlayer && board[1][1] === currentPlayer && board[2][0] === currentPlayer) {
        return true;
    }
    return false;
};

const isBoardFull = () => {
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++) {
            if (board[i][j] === '') {
                return false;
            }
        }
    }
    return true;
};

const handleClick = (event) => {
    const row = parseInt(event.target.dataset.row);
    const col = parseInt(event.target.dataset.col);

    if (board[row][col] !== '') {
        status.textContent = 'Invalid Move. Try again!';
        return;
    }

    board[row][col] = currentPlayer;
    event.target.textContent = currentPlayer;

    if (checkWinner()) {
        status.textContent = `Player ${currentPlayer} wins!`;
        return;
    }

    if (isBoardFull()) {
        status.textContent = 'Game Over!';
        return;
    }

    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
};

cells.forEach(cell => cell.addEventListener('click', handleClick));
