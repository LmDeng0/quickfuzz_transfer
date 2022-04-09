from pandas.core.window.rolling import _Rolling

class ExponentialMovingWindow(_Rolling):
    obj = ...
    com = ...
    min_periods = ...
    adjust = ...
    ignore_na = ...
    axis = ...
    on = ...
    def __init__(
        self,
        obj,
        com=...,
        span=...,
        halflife=...,
        alpha=...,
        min_periods: int = ...,
        adjust: bool = ...,
        ignore_na: bool = ...,
        axis: int = ...,
    ) -> None: ...
    def aggregate(self, func, *args, **kwargs): ...
    agg = ...
    def mean(self, *args, **kwargs): ...
    def std(self, bias: bool = ..., *args, **kwargs): ...
    vol = ...
    def var(self, bias: bool = ..., *args, **kwargs): ...
    def cov(self, other=..., pairwise=..., bias: bool = ..., **kwargs): ...
    def corr(self, other=..., pairwise=..., **kwargs): ...
