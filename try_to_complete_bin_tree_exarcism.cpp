#include<iostream>
#include<queue>
#include<memory>



template<typename T>
struct binary_tree
{
    binary_tree* left_node = nullptr;
    binary_tree* right_node = nullptr;
    T value;

    bool has_left(){
        return !(left_node==nullptr);
    };
    bool has_right(){
        return !(right_node==nullptr);
    };
    std::unique_ptr<binary_tree<T>> left(){
        if(!(has_left()))
            return std::unique_ptr<binary_tree<T>>(nullptr);
        auto target = left_node;
        left_node=nullptr;
        return std::unique_ptr<binary_tree<T>>(target);
        };
    std::unique_ptr<binary_tree<T>>  right(){
        if(has_right())
            return std::unique_ptr<binary_tree<T>>(nullptr);
        auto target = right_node;
        right_node=nullptr;
        return std::unique_ptr<binary_tree<T>>(&target);
        };
    T data(){
        return value;
    }

void insert(T value){
    std::queue<binary_tree<T>* > que ;
    que.push(this);
    while(true){
       binary_tree<T>* elem =  que.front();
        if(elem->value == 0){
            elem->value = value;
            return;
        }
        if(elem->left_node==nullptr){
            elem->left_node = new binary_tree<T>(value);
            return;
        }
        if(elem->right_node==nullptr){
            elem->right_node = new binary_tree<T>(value);
            return;
        }
        que.push(elem->left_node);
        que.push(elem->right_node);
        que.pop();
    }
    //que.front()->value=9;
};
binary_tree(T elem):value(elem){};
binary_tree(std::initializer_list<T> list){

    for( T element:list){
        this->insert(element);
    }
    
};
binary_tree(const binary_tree& tree) {
    value = tree.value;
    if (tree.left_node != nullptr) {
        left_node = new binary_tree(*tree.left_node);
    }
    if (tree.right_node != nullptr) {
        right_node = new binary_tree(*tree.right_node);
    }
}

binary_tree(binary_tree&& tree) noexcept {
    value = std::move(tree.value);
    left_node = tree.left_node;
    right_node = tree.right_node;
    tree.left_node = nullptr;
    tree.right_node = nullptr;
}

};

template<typename T>
using tree_ptr = typename std::unique_ptr<binary_tree<T>>;

template<typename T>
static void test_leaf(const tree_ptr<T> &tree, 
                      const T& data, bool has_left, bool has_right)
{
    std::cout<<(data == tree->data());    
    std::cout<<((bool) tree->left() == has_left);
    std::cout<<((bool) tree->right() == has_right);

}

template<typename T>
static tree_ptr<T> make_tree(const std::vector<T> &data)
{
    if (data.empty())
        return tree_ptr<T>(nullptr);
    auto data_iter = data.begin();
    auto tree = tree_ptr<T>(new binary_tree<T>(*data_iter));
    ++data_iter;
    for (; data_iter != data.end(); ++data_iter)
    {
        tree->insert(*data_iter);    
    }
    return tree;
}

    
    
int main(){
    auto tested = make_tree<uint32_t>({4, 2});
    test_leaf<uint32_t>(tested, 4, true, false);
    
    test_leaf<uint32_t>(tested->left(), 2, false, false);
    std::cout<<tested->left()->data();
}