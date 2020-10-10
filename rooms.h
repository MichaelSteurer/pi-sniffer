#ifndef H_ROOMS
#define H_ROOMS

#include <stdlib.h>
#include <stdbool.h>
#include "device.h"
#include "accesspoints.h"

/*
    Rooms
*/

// A weight for a sensor in a room
struct weight
{
    const char* name;
    double weight;
    struct weight* next;  // next ptr
};

// A group
struct group
{
    const char* name;
    struct group* next;         // next ptr
    double group_total;         // across all aps and rooms
};


// A room in a group
struct room
{
    const char* name;
    struct group* group;        // identity mapped group
    struct room* next;          // next ptr
    double room_score;          // calculated during scan, one ap
    double phone_total;         // how many phones
    double tablet_total;        // how many tablet
    double computer_total;      // how many computers
    double watch_total;         // how many watches
    double beacon_total;        // how many beacons
};

/*
  Get top k rooms sorted by total, return count maybe < k
*/
int top_k_by_room_score(struct room* result[], int k, struct room* room_list);

// Initialize the rooms structure on startup
void read_configuration_file(const char* path, struct room** room_list, struct group** group_list, struct AccessPoint** access_points_list);


// ------------------------------------------------------------------

struct beacon
{
    const char* name;
    const char* mac_address;
    int64_t mac64;
    const char* alias;
};


#endif