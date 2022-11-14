#include <concepts>
#include <memory>

template <class _Type, class... _Params>
  requires std::is_constructible_v<_Type, _Params...>
[[nodiscard("smart pointer")]] auto unew(_Params &&...params) {
  return std::make_unique<_Type>(std::forward<_Params>(params)...);
}

template <class _Type, class... _Params>
  requires std::is_constructible_v<_Type, _Params...>
[[nodiscard("smart pointer")]] auto snew(_Params &&...params) {
  return std::make_shared<_Type>(std::forward<_Params>(params)...);
}

template <class _Type, class... _Params>
  requires std::is_constructible_v<_Type, _Params...>
[[nodiscard("smart pointer")]] auto dnew(_Params &&...params) {
  return unew<_Type>(std::forward<_Params>(params)...);
}