vector<int> topView(Node *root)
    {
        vector<int> ans; 
        if(root == NULL) return ans; 
        // it will store the {vertical line ka value, node ka value corresponding to it}
        // use map bcz it store keys in sorted manner mp({key,value}).
        map<int,int> mpp;
        // it will store({node ka value, value of the vertical line}) 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 

        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            // node = node ka data 
            Node* node = it.first; 
            // line = vertical line ka value
            int line = it.second; 
            // agar 0th vertical line nhi h mp me toh us line k coorresponding 
            // jo node h uska value map me insert kr do 
            // if condition isley lgate hai taki us vartical line k corresponding jo first node hai usii ka value jaye mp me
            // taki jb dubara same vartical line ayye queue me toh map me ussi line ka value update na ho jaye
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        // as it is not unordered map it will store the vertical line value in sorted order (-2,-1,0,1,2) and the data corresponding to each line 
        // it.first will correspond to -2 and it.second will correspond to the node ka value .
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans; 
    }
