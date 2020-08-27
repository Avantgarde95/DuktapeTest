declare function print(value: string): void;

function printSquares(n: number) {
    for (let i = 0; i <= n; i++) {
        const k = i * i;

        if (k <= n) {
            print(k + ' ');
        } else {
            print('\n');
            return;
        }
    }
}

printSquares(100);
print('Done!\n');
