import numpy
def numIslands(grid):
    h,l=len(grid),len(grid[0])
    is_step = numpy.zeros_like(grid)
    print(is_step)
    N = 0
    def dfs(i,j):
        if i<0 or i>=h or j<0 or j>=l or grid[i][j]=='0':
            return
        if is_step[i][j]:return
        is_step[i][j]=1
        dfs(i-1,j)
        dfs(i+1,j)
        dfs(i,j+1)
        dfs(i,j-1)
    for i in range(h):
        for j in range(l):
            if grid[i][j]=="1" and not is_step[i][j]:
                dfs(i,j)
                N+=1
    return N

grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
print(numIslands(grid))

