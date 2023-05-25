#include<bits/stdc++.h>
using namespace std;

class Solution {
    // In worst case if all elements has same initial color then the 
    // worst case time complexity is going to be O(N x M)
    private:
    void dfs (int row, int col, vector<vector<int>> &ans, vector<vector<int>>image, 
    int delRow[], int delCol[], int initialColor, int newColor) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        for (int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == initialColor
            && ans[nRow][nCol] != newColor) {
                dfs (nRow, nCol, ans, image, delRow, delCol, initialColor, newColor);
            }
        }
    }
    
    
    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        dfs(sr, sc, ans, image, delRow, delCol, initialColor, newColor);
        
        return ans;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}