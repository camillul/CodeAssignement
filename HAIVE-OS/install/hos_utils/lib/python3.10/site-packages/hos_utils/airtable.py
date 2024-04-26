"""
This file handle the db connection with the authentification information
"""
import requests
from typing import List

from ament_index_python.packages import get_package_share_directory

import hos_utils.file as FileUtils


def load_table(access_token: str, base_id: str, table_name: str) -> (str, object):
  r = requests.get(f'https://api.airtable.com/v0/{base_id}/{table_name}', headers={'Authorization': f'Bearer {access_token}'})
  obj = r.json()
  if 'error' in obj:
    return f"airtable.load_table: {obj['error']['type']} error when loading db data >> `{obj['error']['message']}`", r.json()
  return "", r.json()


CORE_TABLES = [
  'devices',
  'apis',
  'api_serializers',
  'streams',
  'robot_state',
]
def FLEET_TABLE(fleet_name: str): return f'fleet-{fleet_name}'


AT_KEY_ID = 'id'
AT_KEY_CREATED = 'createdTime'
AT_KEY_FIELDS = 'fields'


def load_db(access_token: str, base_id: str, fleet_name: str, create_backup: bool = True) -> (str, List[dict]):
  db_data = []

  for t in CORE_TABLES + [FLEET_TABLE(fleet_name)]:
    error, data = load_table(access_token, base_id, t)
    if error:
      return error, None

    if create_backup:
      path = f"{get_package_share_directory('hos_device_layer')}/db/{t}.json"

      if not FileUtils.create_file(path):
        return f"Failed to create file in `{path}`.", None

      error = FileUtils.save_json(path, data)
      if error:
        return error, None

      print(f"SAVED DB INFO IN: {path}")

    db_data.append(data['records'])

  return "", db_data

def load_db_from_file(fleet_name: str) -> (str, List[dict]):
  db_data = []

  for t in CORE_TABLES + [FLEET_TABLE(fleet_name)]:
    path = f"{get_package_share_directory('hos_device_layer')}/db/{t}.json"
    
    data, error = FileUtils.load_json(path)
    if error:
      return error, None

    db_data.append(data['records'])

  return "", db_data
