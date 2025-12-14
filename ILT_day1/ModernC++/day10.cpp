#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>

class CANHandler
{
private:
    std::unordered_map<int, std::string> myHandler;

public:
    void addHandler(int key, std::string value)
    {
        myHandler[key] = value;
        std::cout << "Handler added: key = " << key << " value = " << value << std::endl;
    }

    void removeHandler(int messageKey)
    {
        if (myHandler.erase(messageKey))
        {
            std::cout << "Handler Removed: key = " << messageKey << std::endl;
        }
        else
        {
            std::cout << "Handler not Removed: key = " << messageKey << std::endl;
        }
    }

    void findHandler(int messageKey)
    {
        auto it = myHandler.find(messageKey);
        if (it != myHandler.end())
        {
            std::cout << "Handler found: key = " << messageKey << " value = " << myHandler[messageKey] << std::endl;
        }
        else
        {
            std::cout << "Handler not found: key = " << messageKey << std::endl;
        }
    }

    void displayHandler() const
    {
        for (auto &pair : myHandler)
        {
            std::cout << "key = " << pair.first << " value = " << pair.second << std::endl;
        }
    }
};

void displayStack(std::stack<int> stk)
{
    while (!stk.empty())
    {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;
}

int main()
{
    CANHandler handler;
    handler.addHandler(1, "EngineControl");
    handler.addHandler(2, "TransmissionControl");
    handler.addHandler(3, "BrakeControl");
    handler.displayHandler();

    handler.removeHandler(2);
    handler.displayHandler();

    handler.findHandler(3);

    std::stack<int> st;
    st.push(5);
    st.pop();
    st.push(10);
    st.push(15);
    st.push(25);
    st.push(11);
    
    displayStack(st);

    std::queue<int> q;
    q.push(5);
    q.push(10);
    q.pop();
    if (!q.empty())
    {
        std::cout << q.front() << std::endl;
        std::cout << q.back() << std::endl;
    }

    std::priority_queue<int> pq;   
    pq.push(10);
    pq.push(5);
    pq.push(20);

    std::cout << pq.top() << std::endl;  
    pq.pop();
    std::cout << pq.top() << std::endl;  

    return 0;
}