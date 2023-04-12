#include <muParser.h>

#include <memory>
#include <string>

class MuparserFun
{
public:
  MuparserFun(const MuparserFun &m)
    : m_parser(m.m_parser)
  {
    m_parser.DefineVar("t", &m_var1);
    m_parser.DefineVar("y", &m_var2);
  };

  MuparserFun(const std::string &s)
  {
    try
      {
        m_parser.DefineVar("t", &m_var1);
        m_parser.DefineVar("y", &m_var2);
        m_parser.SetExpr(s);
      }
    catch (mu::Parser::exception_type &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
  };

  double
  operator()(const double &t,const double &y)
  {
    double ret = 0;

    m_var1 = t;
    m_var2 = y; //TODO: need to understand how to make a 2-var muparser function

    try
      {
        ret = m_parser.Eval();
      }
    catch (mu::Parser::exception_type &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
    return ret;
  };

private:
  double     m_var1;
  double     m_var2;
  mu::Parser m_parser;
};