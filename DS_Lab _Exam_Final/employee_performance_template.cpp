#include <iostream>
#include <vector>
using namespace std;

class Employee {
	public:
		int employeeID;
		string name;
		float sales;
		float customerSatisfaction;
		float projectCompletion;
		float performanceScore;

		Employee(int employeeID, string name, float customerSatisfaction, float projectCompletion) {
			this->EmployeeID=employeeID;
			this->name=name;
			this->customerSatisfaction=customerSatisfaction;
			this->projectCompletion=projectCompletion;
		}

		void calculatePerformanceScore() {

		}
};

class MaxHeap {
	public:
		vector<Employee> employeeHeap;

		int getParent(int child) {
			  int parent = (child - 1) / 2;
        return parent;

		}

		int getLeft(int parent) {


		}

		int getRight(int parent) {

		}

		void swap(Employee* a, Employee* b) {
			Employee temp = *a;
			*a = *b;
			*b = temp;
		}

		void heapifyUp(int node) {


			      int parentNode;
        if (node == 0)
        {
            return;
        }
        parentNode = getParent(node);
        if (employeeHeap[node].performanceScore < employeeHeap[parentNode].performanceScore)
        {
            swap(&employeeHeap[node], &employeeHeap[parentNode]);
            heapifyUp(parentNode);
        }

		}




		void heapifyDown(int node) {

			   int size = employeeHeap.size();
        int smallest = node;
        int left = getLeft(node);
        int right = getRight(node);




        if (left < size && employeeHeap[left].performanceScore  < employeeHeap[smallest].performanceScore )
        {
            smallest = left;
        }
        if (right < size && employeeHeap[right].performanceScore < employeeHeap[smallest].performanceScore )
        {
            smallest = right;
        }
        if (smallest != node)
        {
            swap(&employeeHeap[node], &employeeHeap[smallest]);
            heapifyDown(smallest);
        }

		}

		void insertEmployee(Employee emp) {

		}

		void getTopRankingEmployee() {

		}

		void updatePerformance(int employeeID, float newSales, float newCS, float newPCE) {


		}

		void displayEmployees() {
			if (employeeHeap.empty()) {
				cout << "No Employees." << endl;
				return;
			}
			cout << "Employee Rankings:" << endl;
			for (const Employee& emp : employeeHeap) {
				cout << "Employee ID: " << emp.employeeID << ", Name: " << emp.name << ", Performance Score: " << emp.performanceScore << endl;
			}
		}

};

int main() {
	MaxHeap employeeMaxHeap;

	while (true) {
		cout << "\nMenu:\n";
		cout << "1. Enter a new employee details\n";
		cout << "2. Get the top-ranking employee\n";
		cout << "3. Update an employee's scores\n";
		cout << "4. Display employee rankings\n";
		cout << "5. Exit\n";

		int choice;
		cin >> choice;

		switch (choice) {
			case 1: {
				int id;
				string name;
				float sales, cs, pce;
				cout << "Enter Employee ID: ";
				cin >> id;
				cin.ignore(); // Clear newline character from the buffer
				cout << "Enter Employee Name: ";
				getline(cin, name);
				cout << "Enter Sales (in percentage): ";
				cin >> sales;
				cout << "Enter Customer Satisfaction (in percentage): ";
				cin >> cs;
				cout << "Enter Project Completion Efficiency (in percentage): ";
				cin >> pce;

				Employee newEmployee(id, name, cs, pce, sales);
				newEmployee.calculatePerformanceScore();
				employeeMaxHeap.insertEmployee(newEmployee);
				cout << "Employee added successfully!" << endl;
				break;
			}
			case 2: {
				employeeMaxHeap.getTopRankingEmployee();
				break;
			}
			case 3: {
				int empID;
				float newSales, newCS, newPCE;
				cout << "Enter Employee ID to update scores: ";
				cin >> empID;
				cout << "Enter new Sales (in percentage): ";
				cin >> newSales;
				cout << "Enter new Customer Satisfaction (in percentage): ";
				cin >> newCS;
				cout << "Enter new Project Completion Efficiency (in percentage): ";
				cin >> newPCE;
				employeeMaxHeap.updatePerformance(empID, newSales, newCS, newPCE);
				break;
			}
			case 4: {
				employeeMaxHeap.displayEmployees();
				break;
			}
			case 5:
				cout << "Exiting the program." << endl;
				return 0;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	}

	return 0;
}
