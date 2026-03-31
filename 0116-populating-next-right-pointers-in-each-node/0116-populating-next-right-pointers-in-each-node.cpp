class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* leftmost = root;
        
        // Iterate through levels
        while (leftmost->left) {
            Node* head = leftmost;
            
            // Iterate through the current level to connect the next level
            while (head) {
                // Connection 1: Children of the same parent
                head->left->next = head->right;
                
                // Connection 2: Children of adjacent parents
                if (head->next) {
                    head->right->next = head->next->left;
                }
                
                head = head->next;
            }
            
            // Move to the next level down
            leftmost = leftmost->left;
        }
        
        return root;
    }
};