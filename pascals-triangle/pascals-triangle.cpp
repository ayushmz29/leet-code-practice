class Solution 
{
public:
    vector< vector<int> > generate(int numRows) 
    {
        vector<vector<int>> ans;
        for(int i=0; i<numRows;i++)
        {    
            ans.push_back(pascalGen(i));
        }
        return ans;
        
    }
    
    vector<int> pascalGen(int rowIndex)
    {
        vector<int> currow;

        // 1st element of every row is 1
        currow.push_back(1);

        // Check if the row that has to
        // be returned is the first row
        if (rowIndex == 0)
        {
            return currow;
        }

        // Generate the previous row
        vector<int> prev = pascalGen(rowIndex - 1);

        for(int i = 1; i < prev.size(); i++)
        {

            // Generate the elements
            // of the current row
            // by the help of the
            // previous row
            int curr = prev[i - 1] + prev[i];
            currow.push_back(curr);
        }
        
        currow.push_back(1);
     
        // Return the row vector
        return currow;
    }
};