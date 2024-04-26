import json
import yaml
import traceback
import os
from pathlib import Path


def load_json(path: str) -> (object, str):
  try:
    with open(path, 'r') as f:
      obj = json.load(f)
      return obj, ''
  except:
    return None, traceback.format_exc()

def save_json(path: str, data: dict) -> str:
  try:
    with open(path, 'w') as f:
      json.dump(data, f, indent=2)
      return ''
  except:
    return traceback.format_exc()

def load_yaml(path: str) -> (object, str):
  try:
    with open(path, 'r') as f:
      obj = yaml.safe_load(f)
      return obj, ''
  except:
    return None, traceback.format_exc()

def create_file(path) -> bool:
  try:
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, 'w').close()
    return True
  except:
    return False

def create_log_file(file_name, sub_folder: str = "") -> str:
  path = f'{Path.home()}/.haive_os/log/{sub_folder}/{file_name}'
  os.makedirs(os.path.dirname(path), exist_ok=True)
  return path

def append_file(file_name: str, data: str) -> str:
  try:
    with open(file_name, 'a') as f:
      f.write(data)
      return ''
  except:
    return traceback.format_exc()
