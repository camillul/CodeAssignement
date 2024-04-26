# Robot state init

On starting the HAIVE-OS, call the robot_state_initilization and select one of these files.
These file need to be in this format :

    - dict : { 
                "meta_data" : String  #Holding the date, the version, and the fleet
                "device_to_update" : List[Dict]  #Insert dictionnary holding hos_state_api information needed, which are device_id and args thatcan be updated for this device
             }