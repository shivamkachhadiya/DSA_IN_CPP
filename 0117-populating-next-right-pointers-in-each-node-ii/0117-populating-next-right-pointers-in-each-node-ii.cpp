class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        queue<Node*> q;
        q.push(root);
        
        // level order traversal karenge
        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;
            
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                // pichle node ka next set karo
                if (prev) prev->next = node;
                prev = node;
                
                // left child add karo
                if (node->left) q.push(node->left);
                // right child add karo
                if (node->right) q.push(node->right);
            }
            
            // last node ka next null hoga
            prev->next = nullptr;
        }
        
        return root;
    }
};
