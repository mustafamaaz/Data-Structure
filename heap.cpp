#include <iostream>
#include <vector>
using namespace std;

class Patient
{
public:
    string name;
    int urgency;

    Patient(string name, int urgency)
    {
        this->name = name;
        this->urgency = urgency;
    }
};

class Heap
{
public:
    vector<Patient> htree;

    int getParent(int child_index)
    {
        int parent = (child_index - 1) / 2;
        return parent;
    }

    int getLeftChild(int parent_index)
    {
        int left = (parent_index * 2) + 1;
        return left;
    }

    int getRightChild(int parent_index)
    {
        int right = (parent_index * 2) + 2;
        return right;
    }
    
    void swap(Patient *a, Patient *b)
    {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }

    void heapifyUp(int node)
    {
        int parentNode;
        if (node == 0)
        {
            return;
        }
        parentNode = getParent(node);
        if (htree[node].urgency < htree[parentNode].urgency)
        {
            swap(&htree[node], &htree[parentNode]);
            heapifyUp(parentNode);
        }
    }
     void insert(Patient patient)
    {
        htree.push_back(patient);
        int index = htree.size() - 1;
        heapifyUp(index);
    }


    void heapifyDown(int node)
    {
        int size = htree.size();
        int smallest = node;
        int left = getLeftChild(node);
        int right = getRightChild(node);




        if (left < size && htree[left].urgency < htree[smallest].urgency)
        {
            smallest = left;
        }
        if (right < size && htree[right].urgency < htree[smallest].urgency)
        {
            smallest = right;
        }
        if (smallest != node)
        {
            swap(&htree[node], &htree[smallest]);
            heapifyDown(smallest);
        }


    }

    

   
    void del()
    {
        if (htree.empty())
        {
            cout << "No appointments to send." << endl;
            return;
        }
        // cout << "Sending next appointment..." << endl;
        // cout << "Name: " << htree[0].name << ", Urgency: " << htree[0].urgency << endl;
        if (htree.size() == 1)
        {
            htree.pop_back();
            return;
        }


        htree[0] = htree.back();
        htree.pop_back();
        heapifyDown(0);
    }

    void updateUrgency(string patientName, int newUrgency)
    {
        int oldurgency;
        for (int i = 0; i < htree.size(); i++)
        {
            if (htree[i].name == patientName)
            {
                oldurgency = htree[i].urgency;
                htree[i].urgency = newUrgency;
                if (newUrgency < oldurgency)
                {
                    heapifyUp(i);
                }
                if(htree[i].urgency < newUrgency)
                {
                    heapifyDown(i);
                }
            }
        }
    }

    void display()
    {
        if (htree.empty())
        {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++)
        {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
    }
};

int main()
{
    Heap priorityQueue;

    while (true)
    {
        cout << "\n==== Priority Queue Menu ====" << endl;
        cout << "1. Schedule Appointment" << endl;
        cout << "2. Display Appointments" << endl;
        cout << "3. Send Next Patient to Doctor" << endl;
        cout << "4. Update Urgency Level" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int urgency;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter urgency level: ";
            cin >> urgency;

            Patient newPatient(name, urgency);
            priorityQueue.insert(newPatient);

            cout << "Appointment scheduled successfully." << endl;
            break;
        }
        case 2:
            priorityQueue.display();
            break;
        case 3:
            priorityQueue.del();
            break;
        case 4:
        {
            string name;
            int newUrgency;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter new urgency level: ";
            cin >> newUrgency;

            priorityQueue.updateUrgency(name, newUrgency);
            cout << "Urgency level updated successfully." << endl;
            break;
        }
        case 5:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
        cout << "\nCurrent Appointments:" << endl;
        priorityQueue.display();
    }
    return 0;
}