class Solution(object):
    def numTilings(self, N):
        MOD = 10**9 + 7

        def matrix_mult(A, B):
            ZB = zip(*B)
            return [[sum(a * b for a, b in zip(row, col)) % MOD
                     for col in ZB] for row in A]

        def matrix_expo(A, K):
            if K == 0:
                return [[+(i==j) for j in xrange(len(A))]
                        for i in xrange(len(A))]
            if K == 1:
                return A
            elif K % 2:
                return matrix_mult(matrix_expo(A, K-1), A)
            B = matrix_expo(A, K/2)
            return matrix_mult(B, B)

        T = [[1, 0, 0, 1],
             [1, 0, 1, 0],
             [1, 1, 0, 0],
             [1, 1, 1, 0]]

        return matrix_expo(T, N)[0][0]
