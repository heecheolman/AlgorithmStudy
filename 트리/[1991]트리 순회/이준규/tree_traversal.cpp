#include <iostream>

using namespace std;

class Bt{ //이진트리
public:
    char val;
    Bt* left;
    Bt* right;
    Bt();
    void setNode(char c) {
        this->val = c;
        left = NULL;
        right = NULL;
    }
};

Bt::Bt(){    // 기본생성자    
    this->val = '0';
    left = NULL;
    right = NULL;
}

void docking(Bt* a, Bt* b, Bt* c){ //이진트리 연결
    a->left = b;
    a->right = c;
}

void preorder(Bt* root){
    if(root == NULL){
        return;
    }

    cout << root->val;

    preorder(root->left);

    preorder(root->right);

}

void inorder(Bt* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);

    cout << root->val;

    inorder(root->right);
}

void postorder(Bt* node){
    if(node == NULL){
        return;
    }

    postorder(node->left);

    postorder(node->right);

    cout << node->val;
}

int main(){
    int n;
    char node, left, right;

    cin >> n;

    Bt *bt = new Bt[n]; // 동적배열생성

    for(int i = 0; i < n; i++){ // A부터 차례로 n  개만큼의 알파벳노드 생성후 두 자식들을 NULL로 초기화
        bt[i].setNode('A'+i);
    }

    for(int i = 0; i < n; i++){
        cin >> node >> left >> right;

        if(left == '.' && right != '.'){           // A의 아스키 코드는 65
            docking(&bt[node - 65], NULL, &bt[right - 65]);
        }else if(left != '.' && right == '.'){
            docking(&bt[node - 65], &bt[left - 65], NULL);
        }else if(left == '.' && right == '.'){
            docking(&bt[node - 65], NULL, NULL);
        }else{
            docking(&bt[node - 65], &bt[left - 65], &bt[right - 65]);
        }
    }

    preorder(&bt[0]);  // 루트인 A 노드부터 넘겨준다
    cout << "\n";
    inorder(&bt[0]);
    cout << "\n";
    postorder(&bt[0]);


    
    delete [] bt; // 배열 소멸
}