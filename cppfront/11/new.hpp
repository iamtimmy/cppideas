#include <memory>
#include <type_traits>

template <class _Type, class... _Params>
std::unique_ptr<_Type> unew(_Params &&...params) {
  static_assert(std::is_constructible<_Type, _Params...>::value,
                "_Type is not constructible from params");
  return std::unique_ptr<_Type>(::new _Type(std::forward<_Params>(params)...));
}

template <class _Type, class... _Params>
std::shared_ptr<_Type> snew(_Params &&...params) {
  static_assert(std::is_constructible<_Type, _Params...>::value,
                "_Type is not constructible from params");
  return std::make_shared<_Type>(std::forward<_Params>(params)...);
}

template <class _Type, class... _Params>
std::unique_ptr<_Type> dnew(_Params &&...params) {
  static_assert(std::is_constructible<_Type, _Params...>::value,
                "_Type is not constructible from params");
  return unew<_Type>(std::forward<_Params>(params)...);
}