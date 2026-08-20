// #include <iostream>

// #include "include/Light.h"
// #include "include/Fan.h"
// #include "include/AC.h"
// #include "include/Camera.h"
// #include "include/DoorLock.h"

// using namespace std;

// int main()
// {

//     Light light(1, "Living Room Light");
//     Fan fan(2, "Bedroom Fan");
//     AC ac(3, "Bedroom AC");
//     Camera camera(4, "Main Gate Camera");
//     DoorLock door(5, "Main Door");

//     cout << "===== SMART HOME TEST =====\n\n";

//     light.setBrightness(80);
//     light.turnOn();

//     cout << endl;

//     fan.setSpeed(3);
//     fan.turnOn();

//     cout << endl;

//     ac.setTemperature(22);
//     ac.turnOn();

//     cout << endl;

//     camera.turnOn();
//     camera.startRecording();

//     cout << endl;

//     door.unlock();

//     cout << endl;

//     cout << "===== POLYMORPHISM TEST =====\n\n";

//     SmartDevice *device;

//     device = &light;
//     device->turnOn();

//     cout << endl;

//     device = &fan;
//     device->turnOn();

//     cout << endl;

//     device = &ac;
//     device->turnOn();

//     cout << endl;

//     device = &camera;
//     device->turnOn();

//     cout << endl;

//     device = &door;
//     device->turnOn();

//     return 0;
// }

// ***Test DeviceManager***
// #include <iostream>
// #include <memory>

// #include "include/DeviceManager.h"
// #include "include/Light.h"
// #include "include/Fan.h"
// #include "include/AC.h"

// using namespace std;

// int main()
// {

//     DeviceManager manager;

//     manager.addDevice(
//         make_unique<Light>(
//             1,
//             "Living Room Light"));

//     manager.addDevice(
//         make_unique<Fan>(
//             2,
//             "Bedroom Fan"));

//     manager.addDevice(
//         make_unique<AC>(
//             3,
//             "Bedroom AC"));

//     manager.listDevices();

//     cout << "\n===== TURNING ON DEVICE 1 =====\n";

//     manager.turnOnDevice(1);

//     cout << "\n===== TURNING ON DEVICE 2 =====\n";

//     manager.turnOnDevice(2);

//     cout << "\n===== CURRENT DEVICES =====\n";

//     manager.listDevices();

//     cout << "\n===== REMOVING DEVICE 2 =====\n";

//     manager.removeDevice(2);

//     cout << "\n===== CURRENT DEVICES =====\n";

//     manager.listDevices();

//     return 0;
// }

//** Put devices inside Rooms*/

// #include <iostream>
// #include <memory>
// #include "include/Room.h"
// #include "include/Light.h"
// #include "include/Fan.h"
// #include "include/AC.h"
// using namespace std;
// int main()
// {
//     Room livingRoom(1, "Living Room");

//     Room bedroom(2, "Bedroom");
//     livingRoom.getDeviceManager().addDevice(
//         make_unique<Light>(
//             1, "Living Room Light"));
//     bedroom.getDeviceManager().addDevice(
//         make_unique<Fan>(
//             2,
//             "Bedroom Fan"));
//     bedroom.getDeviceManager().addDevice(
//         make_unique<AC>(
//             3,
//             "Bedroom AC"));
//     livingRoom.displayRoom();
//     bedroom.displayRoom();
//     return 0;
// }

/***TEST AUTOMATION  with User Interaction***/
// #include <iostream>
// #include <memory>

// #include "include/Room.h"
// #include "include/Light.h"
// #include "include/Fan.h"
// #include "include/AC.h"
// #include "include/DoorLock.h"

// #include "include/SecuritySystem.h"
// #include "include/AutomationEngine.h"

// using namespace std;

// int main()
// {

//     // Create rooms
//     Room livingRoom(1, "Living Room");
//     Room bedroom(2, "Bedroom");

//     // Add devices

//     livingRoom.getDeviceManager().addDevice(
//         make_unique<Light>(
//             1,
//             "Living Room Light"));

//     bedroom.getDeviceManager().addDevice(
//         make_unique<Fan>(
//             2,
//             "Bedroom Fan"));

//     bedroom.getDeviceManager().addDevice(
//         make_unique<AC>(
//             3,
//             "Bedroom AC"));

//     livingRoom.getDeviceManager().addDevice(
//         make_unique<DoorLock>(
//             5,
//             "Main Door"));

//     // Create Security System

//     SecuritySystem securitySystem;

//     // Create Automation Engine

//     AutomationEngine automation(
//         livingRoom,
//         bedroom,
//         securitySystem);

//     // ==============================
//     // MAIN MENU
//     // ==============================

//     int choice;

//     do
//     {

//         cout << "\n=================================\n";
//         cout << "       SMART HOME SYSTEM\n";
//         cout << "=================================\n";

//         cout << "1. Good Morning\n";
//         cout << "2. Good Night\n";
//         cout << "3. Leaving Home\n";
//         cout << "4. Movie Mode\n";
//         cout << "5. Security Status\n";
//         cout << "6. Show Rooms\n";
//         cout << "7. Exit\n";

//         cout << "\nEnter choice: ";

//         cin >> choice;

//         switch (choice)
//         {

//         case 1:
//             automation.goodMorning();
//             break;

//         case 2:
//             automation.goodNight();
//             break;

//         case 3:
//             automation.leavingHome();
//             break;

//         case 4:
//             automation.movieMode();
//             break;

//         case 5:
//             securitySystem.status();
//             break;

//         case 6:
//             livingRoom.displayRoom();
//             bedroom.displayRoom();
//             break;

//         case 7:
//             cout << "Exiting Smart Home..." << endl;
//             break;

//         default:
//             cout << "Invalid choice." << endl;
//         }

//     } while (choice != 7);

//     return 0;
// }

//** check for authentication System */
// #include <iostream>

// #include "include/AuthenticationSystem.h"

// using namespace std;

// int main()
// {

//     AuthenticationSystem auth;
//     auth.login(
//         "admin@smarthome.com",
//         "admin123");
//     auth.createUser(
//         "sanjay@gmail.com",
//         "user123",
//         "Sanjay",
//         Role::USER);

//     auth.login(
//         "sanjay@gmail.com",
//         "user123");

//     cout << "\nIs Admin: "
//          << (auth.isAdmin() ? "YES" : "NO")
//          << endl;

//     // ====================================
//     // LOGOUT
//     // ====================================

//     auth.logout();
//     auth.login(
//         "admin@smarthome.com",
//         "admin123");
//     // ====================================
//     // ADMIN LOGIN
//     // ====================================

//     cout << "\n===== ADMIN LOGIN =====\n";

//     cout << "\nIs Admin: "
//          << (auth.isAdmin() ? "YES" : "NO")
//          << endl;

//     // ====================================
//     // ADMIN CREATES USER
//     // ====================================

//     cout << "\n===== ADMIN CREATES USER =====\n";

//     auth.createUser(
//         "rahul@gmail.com",
//         "rahul123",
//         "Rahul",
//         Role::USER);

//     // ====================================
//     // ADMIN CREATES ANOTHER ADMIN
//     // ====================================

//     cout << "\n===== ADMIN CREATES ADMIN =====\n";

//     auth.createUser(
//         "manager@smarthome.com",
//         "manager123",
//         "Manager",
//         Role::ADMIN);

//     // ====================================
//     // LIST ALL USERS
//     // ====================================
//     cout << "\n===== ALL USERS =====\n";
//     auth.logout();
//     auth.login("manager@smarthome.com", "manager123");
//     auth.listUsers();
//     auth.deleteUser("rahul@gmail.com");
//     auth.deleteUser("admin@smarthome.com");
//     auth.listUsers();
//     return 0;
// }

// complete

#include <iostream>

#include "include/AuthenticationSystem.h"
#include "include/AdminMenu.h"
#include "include/UserMenu.h"

#include "include/Room.h"
#include "include/SecuritySystem.h"
#include "include/AutomationEngine.h"
#include "include/DeviceManager.h"
using namespace std;

int main()
{

    // ======================================
    //
    // WELCOME TO SMART HOME SYSTEM
    //
    // ======================================

    // ======================================
    // DEVICE MANAGER
    // ======================================

    // ======================================
    // SMART HOME OBJECTS
    // ======================================

    Room livingRoom(1, "Living Room");

    Room bedroom(2, "Bedroom");

    SecuritySystem securitySystem;

    AutomationEngine automation(
        livingRoom,
        bedroom,
        securitySystem);

    // ======================================
    // AUTHENTICATION SYSTEM
    // ======================================

    AuthenticationSystem auth;

    // ======================================
    // MENUS
    // ======================================

    AdminMenu adminMenu(
        auth,
        livingRoom,
        bedroom,
        securitySystem,
        automation);

    UserMenu userMenu(
        auth,
        livingRoom,
        bedroom,
        securitySystem,
        automation);

    // ======================================
    // MAIN APPLICATION LOOP
    // ======================================

    int choice;

    while (true)
    {

        cout << "\n";
        cout << "========================================\n";
        cout << "         SMART HOME SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Login\n";
        cout << "2. Exit\n";

        cout << "\nEnter choice: ";

        cin >> choice;

        // ==================================
        // LOGIN
        // ==================================

        if (choice == 1)
        {

            string email;
            string password;

            cout << "\nEmail: ";

            cin >> email;

            cout << "Password: ";

            cin >> password;

            // Try login

            if (auth.login(email, password))
            {

                // ==========================
                // ADMIN
                // ==========================

                if (auth.isAdmin())
                {

                    adminMenu.show();
                }

                // ==========================
                // NORMAL USER
                // ==========================

                else
                {

                    userMenu.show();
                }
            }
        }

        else if (choice == 2)
        {

            cout << "\nExiting Smart Home System...\n";

            break;
        }

        // ==================================
        // INVALID OPTION
        // ==================================

        else
        {

            cout << "\nInvalid choice.\n";
            break;
        }
    }

    return 0;
}