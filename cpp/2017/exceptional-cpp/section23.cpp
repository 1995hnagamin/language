#include <string>

class GenericTableAlgorithm {
  public:
    GenericTableAlgorithm(const std::string &table);
    virtual ~GenericTableAlgorithm();
    bool Process();

  private:
    virtual bool Filter(const Record &);

    virtual bool ProcessRow(const PrimaryKey &) = 0;

    class GenericTableAlgorithmImpl *pimpl_;
};

class MyAlgorithm : public GenericTableAlgorithm {

};
