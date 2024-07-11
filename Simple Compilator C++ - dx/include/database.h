#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "Table.h"

class Database {
public:
    Database(const std::string& name);
    void addTable(const Table& table);
    Table* getTable(const std::string& name);
    void dropTable(const std::string& name);
    void listTables() const;
private:
    std::string name;
    std::vector<Table> tables;
};

#endif // DATABASE_H
