# Warehouse Management System

A C++ application for managing customers, products, and inventory in a simple warehouse system.

The program imports structured data from a text file, validates and stores the data using object-oriented C++ classes, displays the resulting customers, product catalog, and inventory and exports the processed data to a new file.

This project was originally developed as a university programming project for Ostbayerische Technische Hochschule Amberg-Weiden (OTH Amberg-Weiden).

## Features

- Import customer, product, and inventory data from a text file
- Manage customers using unique customer IDs
- Manage different product types
- Track inventory quantities
- Detect duplicate and invalid IDs
- Detect inventory entries referencing nonexistent products
- Handle invalid input using custom exceptions
- Display customers, products, and inventory
- Export processed data to a text file

## Product Types

The application models different products using inheritance:

```text
           Produkt
           /     \
         Dvd    Bluray
```

`Produkt` provides the common product functionality, while `Dvd` and `Bluray` represent specific product types.

## Technologies and Concepts

- C++
- Object-oriented programming
- Classes and inheritance
- Polymorphism
- STL containers (`std::map`)
- Smart pointers (`std::shared_ptr`)
- File I/O
- Exception handling
- Custom exceptions
- Input parsing

## Project Structure

The project contains classes for the different parts of the warehouse system, including:

- `Lagersystem` – central management of customers, products, and inventory
- `Kunde` – customer representation
- `Produkt` – base class for products
- `Dvd` – DVD product type
- `Bluray` – Blu-ray product type
- `FileStore` – importing and exporting warehouse data
- Custom exception classes for handling invalid data
- `main.cpp` – application entry point

## Building and Running

### Requirements

A C++ compiler with support for C++11 or newer is required. For example, [GCC](https://gcc.gnu.org/) with `g++`.

You can check whether `g++` is installed with:

```bash
g++ --version
```

### Compile

Open a terminal in the project directory and compile the source files:

```bash
g++ -std=c++11 *.cpp -o warehouse
```

### Run

On Windows:

```bash
.\warehouse.exe
```

On Linux or macOS:

```bash
./warehouse
```

The application expects `acme.load` to be located in the current project directory.

After execution, the processed data is exported to:

```text
export.txt
```

## Input Data

The application reads warehouse data from:

```text
acme.load
```

The file can contain records for customers, products, and inventory.

Example:

```text
Kunde 23 Gerald Pirkl Kaiser-Wilhelm-Ring 23 92224 Amberg
DVD 230 Das_Sterben_der_Kuehe 93
Bluray 67 Rabby_Hut 22 4K
Lager 230 18
Lager 67 9
```

The program parses these records and stores the corresponding objects and inventory quantities.

## Error Handling

Invalid records are handled using custom exceptions. The application can detect problems such as:

- Duplicate IDs
- Invalid IDs
- Invalid arguments
- Inventory entries for nonexistent products

This allows invalid input to be reported without terminating the entire import process.

## Program Flow

When the application is executed, it:

1. Creates the warehouse system.
2. Reads data from `acme.load`.
3. Parses and validates the input.
4. Stores valid customers, products, and inventory.
5. Prints the customer list.
6. Prints the product catalog.
7. Prints the current inventory.
8. Exports the processed data to `export.txt`.

## Output

After processing the input data, the application creates:

```text
export.txt
```

containing the exported warehouse data.
