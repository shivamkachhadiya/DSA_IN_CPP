class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritical = -1;
        int previousCritical = -1;
        int minimumDistance = INT_MAX;

        int index = 1;
        ListNode* previous = head;
        ListNode* current = head->next;

        // current must have both previous and next nodes
        while (current->next != nullptr) {
            int value = current->val;
            int previousValue = previous->val;
            int nextValue = current->next->val;

            bool isLocalMaximum =
                value > previousValue && value > nextValue;

            bool isLocalMinimum =
                value < previousValue && value < nextValue;

            if (isLocalMaximum || isLocalMinimum) {
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minimumDistance = min(
                        minimumDistance,
                        index - previousCritical
                    );
                }

                previousCritical = index;
            }

            previous = current;
            current = current->next;
            index++;
        }

        // Fewer than two critical points
        if (firstCritical == -1 ||
            firstCritical == previousCritical) {
            return {-1, -1};
        }

        int maximumDistance = previousCritical - firstCritical;

        return {minimumDistance, maximumDistance};
    }
};