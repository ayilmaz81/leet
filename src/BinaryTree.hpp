#include <memory>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

template <typename T>
struct BinaryTreeNode
{
    explicit BinaryTreeNode(T v, std::shared_ptr<BinaryTreeNode<T>> l = nullptr, std::shared_ptr<BinaryTreeNode<T>> r = nullptr) : val(v), left(l), right(r) {}
    T val;
    std::shared_ptr<BinaryTreeNode<T>> left;
    std::shared_ptr<BinaryTreeNode<T>> right;
    bool operator==(const BinaryTreeNode<T> &rhs) const
    {
        if (rhs.val == val)
        {
            bool r = (rhs.right == nullptr && right == nullptr);
            if (r == false)
            {
                if (rhs.right != nullptr && right != nullptr)
                {
                    r = (*rhs.right == *right);
                }
            }

            bool l = (rhs.left == nullptr && left == nullptr);

            if (l == false)
            {
                if (rhs.left != nullptr && left != nullptr)
                {
                    l = (*rhs.left == *left);
                }
            }
            return (l && r);
        }
        return false;
    }
};

using BinaryTreeNodeInt = BinaryTreeNode<int>;

template <typename T>
std::shared_ptr<BinaryTreeNode<T>> deserialize(const std::string &input)
{
    using type = BinaryTreeNode<T>;
    std::shared_ptr<type> root;

    std::stringstream stream(input);
    std::string str;
    if (!getline(stream, str, ' '))
        return root;

    T val;
    std::stringstream tstream(str);
    tstream >> val;
    root = std::make_shared<type>(val);
    int level = 0;
    std::vector<std::shared_ptr<type>> prev{{root}};

    while (!stream.eof())
    {
        std::vector<std::shared_ptr<type>> current;
        int index = 0;
        while ((index / 2) < prev.size() && getline(stream, str, ' '))
        {
            if (str != "null")
            {
                std::stringstream tstream(str);
                tstream >> val;
                current.push_back(std::make_shared<type>(val));

                if (index % 2)
                    prev[index / 2]->right = current.back();
                else
                    prev[index / 2]->left = current.back();
            }
            ++index;
        }
        ++level;
        prev = std::move(current);
    }

    return root;
}
template <typename T>
int depth(const std::shared_ptr<BinaryTreeNode<T>> &root)
{
    if (root == nullptr)
        return 0;

    return std::max(depth(root->left), depth(root->right)) + 1;
}

template <typename T>
std::string serialize(const std::shared_ptr<BinaryTreeNode<T>> &root)
{
    using type = BinaryTreeNode<T>;
    if (root == nullptr)
        return "";
    auto d = depth(root) - 1;
    std::stringstream stream;
    stream << root->val;

    if (root->left == nullptr && root->right == nullptr)
    {
        return stream.str();
    }
    std::queue<std::shared_ptr<type>> q{{root->left, root->right}};

    while (!q.empty())
    {
        auto size = q.size();
        while (size-- > 0)
        {
            auto front = q.front();
            q.pop();
            if (front == nullptr)
            {
                stream << " null";
            }
            else
            {
                stream << " " << front->val;
                if (d != 1)
                {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        --d;
    }
    auto ret = stream.str();
    int right = ret.size();
    while (right - 5 > 0 && ret.compare(right - 5, 5, " null") == 0)
    {
        right -= 5;
    }
    ret.erase(ret.begin() + right, ret.end());
    return ret;
}