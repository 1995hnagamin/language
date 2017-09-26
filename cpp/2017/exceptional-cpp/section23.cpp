#include <string>

class GTAClient;

class GenericTableAlgorithm {
  public:
    GenericTableAlgorithm(const std::string &table, GTAClient &worker);
    ~GenericTableAlgorithm();
    bool Process();

  private:
    class GenericTableAlgorithmImpl *pimpl_;
};

class GTAClient {
  public:
    virtual ~GTAClient() = 0;
    virtual bool Filter(const Record &);
    virtual book ProcessRow(const PrimaryKey &) = 0;
};

bool GTAClient::Filter(const Record &) {
  return true;
}

class MyWorker : public GTAClient {
  // ...
};

int main() {
  GenericTableAlgorithm a("Customer", MyWorker());
  a.Process();
  return 0;
}
