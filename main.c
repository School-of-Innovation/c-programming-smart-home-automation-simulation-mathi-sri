// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int num_room, choice = 0, no_motion_count = 0;
    printf("Enter Number of Rooms: ");
    scanf("%d", &num_room);

    int house[num_room][4];
    for (int i = 0; i < num_room; i++) {
        printf("Room %d:\n", i + 1);
        printf("Light (1 = ON, 0 = OFF): ");
        scanf("%d", &house[i][0]);
        printf("Temperature (°C): ");
        scanf("%d", &house[i][1]);
        printf("Motion Sensor (1 = Detected, 0 = No Motion): ");
        scanf("%d", &house[i][2]);
        printf("Door (1 = Open, 0 = Closed): ");
        scanf("%d", &house[i][3]);
        printf("\n");
    }

    while (choice != 6) {
        printf("\n1. Toggle Light\n2. Read Temperature\n3. Check Motion Sensor\n4. Lock/Unlock Door System\n5. House Status Summary\n6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        int room;
        switch (choice) {
            case 1:
                printf("Enter the room number: ");
                scanf("%d", &room);
                if (room >= 1 && room <= num_room) {
                    house[room - 1][0] = !house[room - 1][0];
                    printf("The Light in Room %d is now %s.\n", room, house[room - 1][0] ? "ON" : "OFF");
                } else {
                    printf("Invalid Room Number!\n");
                }
                break;

            case 2:
                printf("Enter the room number: ");
                scanf("%d", &room);
                if (room >= 1 && room <= num_room) {
                    printf("The Temperature in Room %d is %d°C\n", room, house[room - 1][1]);
                    if (house[room - 1][1] > 30) {
                        printf("WARNING: Room %d is too hot! Consider cooling it down.\n", room);
                    }
                } else {
                    printf("Invalid Room Number!\n");
                }
                break;

            case 3:
                printf("Enter the room number: ");
                scanf("%d", &room);
                if (room >= 1 && room <= num_room) {
                    if (house[room - 1][2] == 0) {
                        printf("No Motion Detected in Room %d.\n", room);
                        no_motion_count++;
                    } else {
                        printf("Motion Detected in Room %d.\n", room);
                        no_motion_count = 0; 
                    }
                    if (no_motion_count >= 5) {
                        for (int i = 0; i < num_room; i++) {
                            house[i][3] = 0;
                        }
                        printf("No Motion is Detected for Long Time so the Doors are Locked.\n");
                        no_motion_count = 0; 
                    }
                } else {
                    printf("Invalid Room Number!\n");
                }
                break;

            case 4:
                printf("Enter the room number: ");
                scanf("%d", &room);
                if (room >= 1 && room <= num_room) {
                    house[room - 1][3] = !house[room - 1][3];
                    printf("The Door in Room %d is now %s.\n", room, house[room - 1][3] ? "Open" : "Closed");
                } else {
                    printf("Invalid Room Number!\n");
                }
                break;

            case 5:
                printf("Room | Light | Temperature | Motion | Door\n");

                int all_lights_on = 1;
                for (int i = 0; i < num_room; i++) {
                    printf(" %2d  |  %s  |     %2d°C    |   %s  |  %s  \n",
                           i + 1,
                           house[i][0] ? "ON " : "OFF",
                           house[i][1],
                           house[i][2] ? "Yes" : "No ",
                           house[i][3] ? "Open" : "Closed");
                }
                break;

            case 6:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
