// From - https://www.codingninjas.com/codestudio/library/next-greater-and-smaller-element-for-every-element-in-an-array
// returns the index of next greater/smaller element. If not exists then -1. (edge case)
vector<int> findNextGreaterElements(vector<int>& arr) {
   int n = (int) arr.size();
   vector<int> answer(n, -1);  
   stack<int> s; 
   for (int i = 0; i < n; i++) { 
       while (!s.empty() && arr[s.top()] < arr[i]) { //finds next greater element
           answer[s.top()] = arr[i];
           s.pop();
       }
       s.push(i);
   }
   return answer;
}
vector<int> findNextSmallerElements(vector<int>& arr) {
   int n = (int) arr.size();
   vector<int> answer(n, -1); 
   stack<int> s; 
   for (int i = 0; i < n; i++) {  
       while (!s.empty() && arr[s.top()] > arr[i]) { //finds next smaller element
           answer[s.top()] = arr[i];
           s.pop();
       }
       s.push(i);
   }
   return answer;
}
