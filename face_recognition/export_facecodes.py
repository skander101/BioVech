#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Export face codes from database to JSON files.
This helps with debugging face recognition issues.
"""

import os
import sys
import json
import sqlite3
import argparse
from pathlib import Path

def export_facecodes_from_db(db_path=None):
    """
    Export face codes from database to JSON files.
    Creates both individual JSON files for each employee and a combined file.
    """
    script_dir = os.path.dirname(os.path.abspath(__file__))
    facecodes_dir = os.path.join(script_dir, "facecodes")
    os.makedirs(facecodes_dir, exist_ok=True)
    
    print(f"Exporting face codes to: {facecodes_dir}")
    
    try:
        # Connect to SQLite database
        if db_path:
            print(f"Using specified database: {db_path}")
            conn = sqlite3.connect(db_path)
        else:
            # Try to find the database in common locations
            possible_paths = [
                "BioVech.sqlite",
                "../BioVech.sqlite",
                "../../BioVech.sqlite",
                "../database/BioVech.sqlite",
                os.path.join(os.path.dirname(script_dir), "BioVech.sqlite")
            ]
            
            conn = None
            for path in possible_paths:
                full_path = os.path.join(script_dir, path) if not os.path.isabs(path) else path
                if os.path.exists(full_path):
                    print(f"Found database at: {full_path}")
                    conn = sqlite3.connect(full_path)
                    break
            
            if conn is None:
                print("Could not find the SQLite database. Please specify the path using --db-path.")
                print("Attempting to create a dummy database connection for testing")
                conn = sqlite3.connect(":memory:")
        
        # Create a cursor
        cursor = conn.cursor()
        
        # Query to check if FACECODE column exists
        try:
            cursor.execute("PRAGMA table_info(EMPLOYE)")
            columns = cursor.fetchall()
            facecode_column_exists = any(col[1].upper() == "FACECODE" for col in columns)
            
            if not facecode_column_exists:
                print("FACECODE column does not exist in the EMPLOYE table")
                return
        except Exception as e:
            print(f"Error checking for FACECODE column: {str(e)}")
            print("This might be normal if connecting to Oracle database or if table doesn't exist")
            facecode_column_exists = True  # Assume it exists and try anyway
        
        # Query to get all employees with face codes
        try:
            cursor.execute("SELECT ID, NOM, PRENOM, FACECODE FROM EMPLOYE WHERE FACECODE IS NOT NULL")
            employees = cursor.fetchall()
            
            if not employees:
                print("No employees with face codes found")
                
                # Try a simple query to check if the table exists
                try:
                    cursor.execute("SELECT COUNT(*) FROM EMPLOYE")
                    count = cursor.fetchone()[0]
                    print(f"Found {count} employees total, but none with face codes")
                except Exception as e:
                    print(f"Error checking employee count: {str(e)}")
                
                return
                
            print(f"Found {len(employees)} employees with face codes")
            
            # Create a combined JSON file
            all_facecodes = {}
            
            for employee in employees:
                emp_id = str(employee[0])
                nom = employee[1]
                prenom = employee[2]
                facecode = employee[3]
                
                print(f"Processing employee ID: {emp_id}, Name: {prenom} {nom}")
                
                # Create individual JSON file
                employee_data = {
                    "employee_id": emp_id,
                    "nom": nom,
                    "prenom": prenom,
                    "face_embedding": facecode
                }
                
                # Save to individual file
                with open(os.path.join(facecodes_dir, f"{emp_id}.json"), 'w') as f:
                    json.dump(employee_data, f, indent=2)
                
                # Add to combined data
                all_facecodes[emp_id] = employee_data
            
            # Save combined file
            with open(os.path.join(facecodes_dir, "facecodes.json"), 'w') as f:
                json.dump(all_facecodes, f, indent=2)
            
            print(f"Successfully exported {len(employees)} face codes")
            
        except Exception as e:
            print(f"Error querying employees: {str(e)}")
            import traceback
            traceback.print_exc()
        
    except Exception as e:
        print(f"Error connecting to database: {str(e)}")
        import traceback
        traceback.print_exc()
    finally:
        if 'conn' in locals() and conn:
            conn.close()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Export face codes from database to JSON files')
    parser.add_argument('--db-path', type=str, help='Path to SQLite database file')
    args = parser.parse_args()
    
    export_facecodes_from_db(args.db_path)
    print("Done!") 