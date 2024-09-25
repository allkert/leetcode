from collections import defaultdict

def main():
    import sys
    n, k = map(int, sys.stdin.readline().strip().split())
    pos = list(map(int, sys.stdin.readline().strip().split()))
    # pos = list(map(int, data[2:2+n]))
    
    mp = defaultdict(int)
    for a in pos:
        mp[a] += 1
    
    tree_count = len([v for v in mp.values() if v > 0])
    
    ans = 0
    t = 0
    while t < k:
        ans += 1
        for i in range(n):
            mp[pos[i] + ans] += 1
        
        t = 0
        for v in mp.values():
            if v > 0:
                t += 1

    print(ans)

if __name__ == "__main__":
    main()
