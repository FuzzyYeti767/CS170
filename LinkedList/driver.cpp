#include "List.h"

#include "PRNG.h"

#include <array>
#include <functional>
#include <iostream>

void PrintNodesAlive()
{
    std::cout << "============================================\n";
    std::cout << "Total number of nodes alive: ";
    std::cout << CS170::List::node_count();
    std::cout << '\n';
    std::cout << "============================================\n";
    std::cout << '\n';
}

void TestPushFront()
{
    std::cout << "TestPushFront..." << '\n';

    int         size = 5;
    CS170::List list;
    for (int i = 1; i <= size; i++)
        list.push_front(i);

    std::cout << list;
    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestPushBack()
{
    std::cout << "TestPushBack..." << '\n';

    int         size = 5;
    CS170::List list;
    for (int i = 1; i <= size; i++)
        list.push_back(i);

    std::cout << list;
    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestPushFrontBack()
{
    std::cout << "TestPushFrontBack..." << '\n';

    int         size = 10;
    CS170::List list;
    for (int i = 1; i <= size; i++)
    {
        list.push_front(i);
        list.push_back(i * 5);
    }

    std::cout << list;
    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestPopFront1()
{
    std::cout << "TestPopFront1..." << '\n';

    int         size = 5;
    CS170::List list;
    for (int i = 1; i <= size; i++)
        list.push_front(i);

    PrintNodesAlive();

    std::cout << list;
    while (!list.empty())
    {
        int item = list.front();
        std::cout << "First item was: " << item << '\n';
        list.pop();
        std::cout << "New list:";
        std::cout << list;
        std::cout << "Items in the list: " << list.size() << '\n';
    }
    std::cout << '\n';

    PrintNodesAlive();
}

void TestPopFront2()
{
    std::cout << "TestPopFront2..." << '\n';


    CS170::List list;

    try
    {
        list.pop();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        std::cout << list.front() << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void TestArray1()
{
    std::cout << "TestArray1..." << '\n';

    int array[] = {4, 7, 12, 5, 9, 23, 7, 11, 15, 2};
    int size    = static_cast<int>(sizeof(array) / sizeof(*array));

    // Construct from array
    CS170::List list(array, size);

    std::cout << list;
    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestArray2()
{
    std::cout << "TestArray2..." << '\n';

    const int array[] = {4, 7, 12, 5, 9, 23, 7, 11, 15, 2};
    int       size    = static_cast<int>(sizeof(array) / sizeof(*array));

    // Construct from array
    CS170::List list(array, size);

    std::cout << list;
    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestArray3()
{
    std::cout << "TestArray3..." << '\n';


    const int array[] = {4, 7, 12, 5, 9, 23, 7, 11, 15, 2};
    int       size    = static_cast<int>(sizeof(array) / sizeof(*array));

    // Construct from array
    try
    {
        CS170::List list(array, 0);

        std::cout << list;
        std::cout << "Items in the list: " << list.size() << '\n';
        std::cout << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        CS170::List list(nullptr, size);

        std::cout << list;
        std::cout << "Items in the list: " << list.size() << '\n';
        std::cout << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

void TestCopyConstructor1()
{
    std::cout << "TestCopyConstructor1..." << '\n';
    int         size = 10;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
        list1.push_front(i * 3);

    PrintNodesAlive();

    std::cout << "List 1: ";
    std::cout << list1;

    CS170::List list2(list1);
    std::cout << "List 2: ";
    std::cout << list2;

    std::cout << '\n';

    PrintNodesAlive();
}

void TestCopyConstructor2()
{
    std::cout << "TestCopyConstructor2..." << '\n';
    int         size = 10;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
        list1.push_front(i * 3);

    std::cout << "List 1: ";
    std::cout << list1;

    const CS170::List list2(list1);
    std::cout << "List 2: ";
    std::cout << list2;

    if (list2.empty())
        std::cout << "List 2 is empty\n";
    else
        std::cout << "List 2 is not empty\n";

    std::cout << "Items in List2: ";
    std::cout << list2.size();
    std::cout << '\n';

    std::cout << '\n';

    PrintNodesAlive();
}

void TestMoveConstructor1()
{
    std::cout << "TestMoveConstructor1..." << '\n';
    int         size = 5;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
        list1.push_front(i * 3);

    std::cout << "List 1: ";
    std::cout << list1;

    const CS170::List list2(std::move(list1 + list1));
    std::cout << "List 2: ";
    std::cout << list2;

    if (list2.empty())
        std::cout << "List 2 is empty\n";
    else
        std::cout << "List 2 is not empty\n";

    std::cout << "Items in List2: ";
    std::cout << list2.size();
    std::cout << '\n';

    std::cout << '\n';

    PrintNodesAlive();
}

void TestAssignment1()
{
    std::cout << "TestAssignment1..." << '\n';
    int         size = 10;
    CS170::List list1, list2;
    for (int i = 1; i <= size; i++)
        list1.push_front(i * 2);

    std::cout << "Before assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    PrintNodesAlive();

    list2 = list1;
    std::cout << "After assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    std::cout << '\n';

    PrintNodesAlive();
}

void TestAssignment2()
{
    std::cout << "TestAssignment2..." << '\n';
    int         size = 10;
    CS170::List list1, list2, list3;
    for (int i = 1; i <= size; i++)
        list1.push_front(i * 2);

    std::cout << "Before assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;
    std::cout << "List 3: ";
    std::cout << list3;

    PrintNodesAlive();

    list3 = list2 = list1;
    std::cout << "After assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;
    std::cout << "List 3: ";
    std::cout << list3;

    std::cout << '\n';

    PrintNodesAlive();
}

void TestAssignment3()
{
    std::cout << "TestAssignment3..." << '\n';
    int         size = 12;
    CS170::List list1, list2;
    for (int i = 1; i <= size; i++)
    {
        list1.push_front(i * 2);
        list2.push_front(i * -2);
    }
    std::cout << "Before assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    PrintNodesAlive();

    list2 = list1 + list2;

    std::cout << "After assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    std::cout << '\n';

    PrintNodesAlive();
}

void TestAssignment4()
{
    std::cout << "TestAssignment4..." << '\n';
    int         size = 12;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
    {
        list1.push_front(i * 2 + -i + 2);
    }
    std::cout << "Before assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;

    PrintNodesAlive();

    list1 = list1;

    std::cout << "After assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;

    std::cout << '\n';

    PrintNodesAlive();
}

void TestAssignment5()
{
    std::cout << "TestAssignment5..." << '\n';
    int         size = 12;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
    {
        list1.push_front(i * 2 + -i + 2);
    }
    std::cout << "Before assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;

    PrintNodesAlive();

    list1 = list1 + list1;

    std::cout << "After assignment:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;

    std::cout << '\n';

    PrintNodesAlive();
}

void TestAddition1()
{
    std::cout << "TestAddition1..." << '\n';

    int         size = 5;
    CS170::List list1, list2;
    for (int i = 1; i <= size; i++)
    {
        list1.push_front(i);
        list2.push_front(i * 10);
    }
    std::cout << "Before addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    PrintNodesAlive();

    CS170::List list3;
    list3 = list1 + list2;
    std::cout << "After addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;
    std::cout << "List 3: ";
    std::cout << list3;
    std::cout << '\n';

    PrintNodesAlive();
}

void TestAddition2()
{
    std::cout << "TestAddition2..." << '\n';

    int         size = 5;
    CS170::List list1, list2;
    for (int i = 1; i <= size; i++)
    {
        list1.push_front(i);
        list2.push_front(i * 10);
    }

    std::cout << "Before addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    PrintNodesAlive();

    const CS170::List list3(list1 + list2);
    std::cout << "List 3: ";
    std::cout << list3;

    CS170::List list4;
    list4 = list1 + list2 + list3;
    std::cout << "After addition:" << '\n';
    std::cout << "List 4: ";
    std::cout << list4;
    std::cout << "Items in the list: " << list4.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestAddAssign1()
{
    std::cout << "TestAddAssign1..." << '\n';

    int         size = 5;
    CS170::List list1, list2;
    for (int i = 1; i <= size; i++)
    {
        list1.push_front(i);
        list2.push_front(i * 10);
    }

    std::cout << "Before addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    PrintNodesAlive();

    list1 += list2;
    std::cout << "After addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;
    std::cout << "Items in the list: " << list1.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestAddAssign2()
{
    std::cout << "TestAddAssign2..." << '\n';

    int         size = 5;
    CS170::List list1, list2;
    for (int i = 1; i <= size; i++)
        list1.push_front(i);

    std::cout << "Before addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    PrintNodesAlive();

    list1 += list2;
    std::cout << "After addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;
    std::cout << "Items in the list: " << list1.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestAddAssign3()
{
    std::cout << "TestAddAssign3..." << '\n';

    int         size = 5;
    CS170::List list1, list2;
    for (int i = 1; i <= size; i++)
        list1.push_front(i);

    std::cout << "Before addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;

    PrintNodesAlive();

    list2 += list1;
    std::cout << "After addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;
    std::cout << "Items in the list: " << list1.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestAddAssign4()
{
    std::cout << "TestAddAssign4..." << '\n';

    int         size = 5;
    CS170::List list1, list2, list3;
    for (int i = 1; i <= size; i++)
    {
        list1.push_front(i);
        list2.push_front(i * 2);
        list3.push_front(i * 5);
    }

    std::cout << "Before addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;
    std::cout << "List 3: ";
    std::cout << list3;

    PrintNodesAlive();

    list1 += list2 += list3;
    std::cout << "After addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "List 2: ";
    std::cout << list2;
    std::cout << "List 3: ";
    std::cout << list3;
    std::cout << "Items in the list: " << list1.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestAddAssign5()
{
    std::cout << "TestAddAssign5..." << '\n';

    int         size = 5;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
        list1.push_front(i);

    std::cout << "Before addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;

    PrintNodesAlive();

    list1 += list1;
    std::cout << "After addition:" << '\n';
    std::cout << "List 1: ";
    std::cout << list1;
    std::cout << "Items in the list: " << list1.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestSubscript1()
{
    std::cout << "TestSubscript1..." << '\n';

    int         size = 10;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
        list1.push_back(i);

    std::cout << "list[0] = " << list1[0] << '\n';
    std::cout << "list[5] = " << list1[5] << '\n';
    std::cout << "list[9] = " << list1[9] << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

void TestSubscript2()
{
    std::cout << "TestSubscript2..." << '\n';

    int         size = 10;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
        list1.push_back(i);

    std::cout << "Original list:\n";
    std::cout << list1;

    list1[0] = 10;
    list1[5] = 20;
    list1[9] = 30;
    list1[7] = list1[2];

    std::cout << "Modified list:\n";
    std::cout << list1;

    std::cout << '\n';

    PrintNodesAlive();
}

void TestSubscript3()
{
    std::cout << "TestSubscript3..." << '\n';

    int         size = 10;
    CS170::List list1;
    for (int i = 1; i <= size; i++)
        list1.push_back(i);

    try
    {
        std::cout << list1[-1] << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        std::cout << list1[size] << '\n';
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    PrintNodesAlive();
}

// generate random numbers between low and high
int RandomInt(int low, int high)
{
    int rnd    = static_cast<int>(CS170::Utils::rand());
    int number = rnd % (high - low + 1) + low;
    return number;
}

// push_front, subscript
void TestStress1(int size)
{
    std::cout << "\nTestStress1..." << '\n';

    CS170::List list;
    for (int i = 1; i <= size; i++)
        list.push_front(RandomInt(1, 9));

    // std::cout << list;
    int sum = 0;
    for (int i = 0; i < size; i += 10)
        sum += list[i];

    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << "Sum of 10%: " << sum << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

// push_front
void TestStress2(int size)
{
    std::cout << "\nTestStress2..." << '\n';

    CS170::List list;
    for (int i = 1; i <= size; i++)
        list.push_front(i);

    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

// push_front, rotate the items
void TestStress3(int size)
{
    std::cout << "\nTestStress3..." << '\n';

    CS170::List list;
    for (int i = 0; i < size; i++)
        list.push_front(RandomInt(1, 9));

    // std::cout << list;
    for (int i = 0; i < size; i++)
    {
        int item = list.front();
        list.pop();
        list.push_back(item);
        // std::cout << list;
    }
    // std::cout << list;
    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << '\n';

    PrintNodesAlive();
}

// push_front, subscript
void TestStress4(int size, int value)
{
    std::cout << "\nTestStress4..." << '\n';

    CS170::List list;
    for (int i = 0; i < size; i++)
        list.push_front(RandomInt(1, 9));

    // std::cout << list;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (list[i] == value)
            count++;
    }
    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << "The number " << value << " appears " << count << " times in the list" << '\n';

    std::cout << '\n';

    PrintNodesAlive();
}

// push_front, subscript
void TestStress5(int size)
{
    std::cout << "\nTestStress5..." << '\n';

    CS170::List list;
    int         low = 1, high = 9;
    for (int i = 0; i < size; i++)
        list.push_front(RandomInt(low, high));

    // std::cout << list;
    int total = 0;
    for (int i = 1; i <= high; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
            if (list[j] == i)
                count++;

        total += count;
        std::cout << "The number " << i << " appears " << count << " times in the list" << '\n';
    }
    std::cout << "Items in the list: " << list.size() << '\n';
    std::cout << "Items in the list: " << total << '\n';

    std::cout << '\n';

    PrintNodesAlive();
}

const std::array<std::function<void(void)>, 31> Tests = {
    TestPushFront,                 // Test 1
    TestPushBack,                  // Test 2
    TestPushFrontBack,             // Test 3
    TestPopFront1,                 // Test 4
    TestPopFront2,                 // Test 5
    TestArray1,                    // Test 6
    TestArray2,                    // Test 7
    TestArray3,                    // Test 8
    TestCopyConstructor1,          // Test 9
    TestCopyConstructor2,          // Test 10
    TestMoveConstructor1,          // Test 11
    TestAssignment1,               // Test 12
    TestAssignment2,               // Test 13
    TestAssignment3,               // Test 14
    TestAssignment4,               // Test 15
    TestAssignment5,               // Test 16
    TestAddAssign1,                // Test 17
    TestAddAssign2,                // Test 18
    TestAddAssign3,                // Test 19
    TestAddAssign4,                // Test 20
    TestAddAssign5,                // Test 21
    TestSubscript1,                // Test 22
    TestSubscript2,                // Test 23
    TestSubscript3,                // Test 24
    TestAddition1,                 // Test 25
    TestAddition2,                 // Test 26
    [] { TestStress1(100000); },   // Test 27
    [] { TestStress2(1000000); },  // Test 28
    [] { TestStress3(1000000); },  // Test 29
    [] { TestStress4(50000, 3); }, // Test 30
    [] { TestStress5(10000); },    // Test 31
};

int main()
{
    std::cout << "Enter test case number 1 to " << Tests.size() << ", or enter 0 to run them all.\n";
    unsigned test = 0;
    if (std::cin >> test)
    {
        if (test == 0 || test > Tests.size())
        {
            test = 1;
            for (const auto& test_function : Tests)
            {
                try
                {
                    test_function();
                }
                catch (...)
                {
                    std::cout << "Test " << test << " revealed something bad in the List class\n";
                }
                ++test;
            }
        }
        else
        {
            const auto& test_function = Tests[test - 1];
            try
            {
                test_function();
            }
            catch (...)
            {
                std::cout << "Test " << test << " revealed something bad in the List class\n";
            }
        }
    }


    std::cout << "============================================\n";
    std::cout << "Total number of Lists created: ";
    std::cout << CS170::List::list_count();
    std::cout << '\n';
    std::cout << "============================================\n";
    std::cout << '\n';

    PrintNodesAlive();

    return 0;
}
