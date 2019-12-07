USPopData.tsv:
Yearly Population of USA since 1960

    Source: https://fred.stlouisfed.org/series/POPTOTUSA647NWDB
    Format:
        Line 0: Num_Test1 Num_Train Num_Test1
        Lines: Num Population  Year
    Delimiter: "    " (tab)

    Training (39): [10, 48]
        year:    [1970, 2008]

    Testing (20):     [0, 9] U [49, 58]
      year:     [1960, 1969] U [2009, 2018]


New Dataset:
    source: http://berkeleyearth.org/data/ (monthly averaged summary)

    % This file contains a detailed summary of the land-surface average
    % results produced by the Berkeley Averaging method.  Temperatures are
    % in Celsius and reported as anomalies relative to the Jan 1951-Dec 1980
    % average.  Uncertainties represent the 95% confidence interval for
    % statistical and spatial undersampling effects.
    %
    % The current dataset presented here is described as:
    %
    %   Estimated Global Land-Surface TAVG based on the Complete Berkeley Dataset
    %
    %
    % This analysis was run on 14-Nov-2019 08:22:48
    %
    % Results are based on 48595 time series
    %   with 19816892 data points
    %
    % Estimated Jan 1951-Dec 1980 absolute temperature (C): 8.63 +/- 0.05
    %
    % As Earth's land is not distributed symmetrically about the equator, there
    % exists a mean seasonality to the global land-average.
    %
    % Estimated Jan 1951-Dec 1980 monthly absolute temperature:
    %      Jan   Feb   Mar   Apr   May   Jun   Jul   Aug   Sep   Oct   Nov   Dec
    %      2.62  3.22  5.32  8.33 11.33 13.46 14.33 13.87 12.08  9.24  6.10  3.66
    % +/-  0.06  0.06  0.07  0.06  0.06  0.06  0.06  0.06  0.07  0.06  0.07  0.06
    %
    % For each month, we report the estimated land-surface average for that
    % month and its uncertainty.  We also report the corresponding values for
    % year, five-year, ten-year, and twenty-year moving averages CENTERED about
    % that month (rounding down if the center is in between months).  For example,
    % the annual average from January to December 1950 is reported at June 1950.
    %
    %                  Monthly          Annual          Five-year        Ten-year        Twenty-year
    % Year, Month,  Anomaly, Unc.,   Anomaly, Unc.,   Anomaly, Unc.,   Anomaly, Unc.,   Anomaly, Unc.
