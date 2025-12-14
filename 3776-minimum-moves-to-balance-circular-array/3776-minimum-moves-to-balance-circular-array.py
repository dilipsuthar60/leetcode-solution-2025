class Solution:
   def minMoves(self, balance):
    n = len(balance)
    total = sum(balance)
    if total < 0:
        return -1

    # find the negative index
    neg = -1
    for i in range(n):
        if balance[i] < 0:
            neg = i
            break

    # already valid
    if neg == -1:
        return 0

    need = -balance[neg]
    suppliers = []

    for i in range(n):
        if i == neg or balance[i] == 0:
            continue
        dist = min((i - neg) % n, (neg - i) % n)
        suppliers.append((dist, balance[i]))

    suppliers.sort()

    moves = 0
    for dist, supply in suppliers:
        take = min(supply, need)
        moves += take * dist
        need -= take
        if need == 0:
            break

    return moves
