#include <iostream>
#define MAX 5

using namespace std;

class Airport
{
public:
    string emergencylandingQueue[MAX];
    string landingQueue[MAX];
    string takeoffStack[MAX];
    int front, rear, Efront, Erear;
    int top;

    Airport()
    {
        Efront = -1;
        Erear = -1;
        front = -1;
        rear = -1;
        top = -1;
    }
    ~Airport()
    {
        cout << "Destructor called, Airport object is being destroyed." << endl;
    }
    void requestEmergencyLanding(string planeID);
    void RequestLanding(string planeID);
    void RequestTakeoff(string planeID);
    void landingPlane();
    void takeoffPlane();
    void ShowlandingRequest();
    void ShowTakeoffRequest();
    void ShowEmergency();
};
void Airport::requestEmergencyLanding(string planeID)
{
    if (Efront == (Erear+1)%MAX)
    {
        cout << "Landing queue is full, plane " << planeID << " cannot land right now.\n";
        return;
    }
    else if (Efront == -1)
    {
        Efront = Erear = 0;
        emergencylandingQueue[Erear] = planeID;
        cout << "Plane " << planeID << " added to Emergency landing queue.\n";
    }
    else
    {
        Erear = (Erear + 1) % MAX;
        emergencylandingQueue[Erear] = planeID;
        cout << "Plane " << planeID << " added to Emergency landing queue.\n";
    }
}
void Airport::RequestLanding(string planeID)
{
    if (front == (rear+1)%MAX)
    {
        cout << "Landing queue is full, plane " << planeID << " cannot land right now.\n";
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        landingQueue[rear] = planeID;
        cout << "Plane " << planeID << " added to landing queue.\n";
    }
    else
    {
        rear = (rear + 1) % MAX;
        landingQueue[rear] = planeID;
        cout << "Plane " << planeID << " added to landing queue.\n";
    }
}

void Airport::RequestTakeoff(string planeID)
{
    if (top == MAX - 1)
    {
        cout << "Takeoff stack is full, plane " << planeID << " cannot take off right now.\n";
        return;
    }
    else if (top == -1)
    {
        cout << "No plane to takeoff please add plane in the stack first\n";
        top++;
        takeoffStack[top] = planeID;
    }
    else
    {
        takeoffStack[++top] = planeID;
        cout << "Plane " << planeID << " added to takeoff stack.\n";
    }
}
void Airport::landingPlane()
{
    if (Efront != -1)
    {
        cout << "Plane " << emergencylandingQueue[Efront] << " is Emergency landing.\n";
        emergencylandingQueue[Efront]="";
        Efront++;
        if (Efront == Erear)
        {
            Efront = Erear = -1;
        }
        else
        {
            Efront=(Efront+1)%MAX;
        }
    }
    else
    {
        if (front == -1)
        {
            cout << "No planes waiting to land.\n";
        }
        else
        {
            cout << "Plane " << landingQueue[front] << " is landing.\n";
            landingQueue[front]="";
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front=(front+1)%MAX;
            }
        }
    }
}
void Airport::takeoffPlane()
{
    if (top == -1)
    {
        cout << "No planes waiting to take off.\n";
    }
    else
    {
        cout << "Plane " << takeoffStack[top] << " is taking off.\n";
        takeoffStack[top]="";
        top--;
    }
}
void Airport::ShowlandingRequest()
{
    for (int i = front; i <= rear; i++)
    {
        cout << landingQueue[i] << "  ";
    }
    cout << endl;
}
void Airport::ShowTakeoffRequest()
{
    for (int i = top; i > -1; i--)
    {
        cout << takeoffStack[i] << "  ";
    }
    cout << endl;
}
void Airport::ShowEmergency()
{
    for (int i = Efront; i <= Erear; i++)
    {
        cout << emergencylandingQueue[i] << "  ";
    }
    cout << endl;
}

int main()
{
    Airport a;
    int x;
    string y;
    do
    {
        cout << "1. Request Landing\n2. Request Takeoff\n3. Request Emergency Landing\n4. Land the Plane\n5. Takeoff The Plane\n6. Show Landing Queu\n7. Show The Takeoff Stack\n8. Show Emergency Queue\n9. Exit" << endl;
        ;

        cout << "Enter The Operation" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Enter the Plane Id Want to Land" << endl;
            cin >> y;
            a.RequestLanding(y);
            break;
        case 2:
            cout << "Enter The Id Of Plane Want To Takeoff" << endl;
            cin >> y;
            a.RequestTakeoff(y);
            break;
        case 3:
            cout << "Enter the Plane Id Want to Emergency Land" << endl;
            cin >> y;
            a.requestEmergencyLanding(y);
            break;
        case 4:
            a.landingPlane();
            break;
        case 5:
            a.takeoffPlane();
            break;
        case 6:
            a.ShowlandingRequest();
            break;
        case 7:
            a.ShowTakeoffRequest();
            break;
        case 8:
            a.ShowEmergency();
            break;
        case 9:
            cout << "Exting.............";
            break;
        default:
            cout << "Option Not Matched";
        }
    } while (x != 9);

    return 0;
}