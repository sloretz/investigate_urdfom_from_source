#include <iostream>

#include <urdf_model/model.h>
#include <urdf_parser/urdf_parser.h>

int main()
{
  urdf::ModelInterface mi;
  urdf_export_helpers::URDFVersion uver("4.1");
  mi.name_ = "foobar";
  std::cout << "Hello world! " << mi.name_ << " " << uver.getMajor() << "." << uver.getMinor() << "\n";
  return 0;
}
