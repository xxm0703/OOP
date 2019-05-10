package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.impl.queries.*;

import java.time.Duration;

public final class Trips {

    public static TripQuery withOrigin(String origin) {
        return new QueryByOrigin(origin);
    }

    public static TripQuery withDestination(String destination) {
        return new QueryByDestination(destination);
    }

    public static TripQuery via(String via) {
        return new QueryByMiddlePoint(via);
    }

    public static TripQuery withMaxDuration(Duration duration) {
        return new QueryByDuration(duration);
    }

    public static TripQuery withMaxLayoverDuration(Duration duration) {
        return new QueryByLayoverDuration(duration);
    }

    public static TripQuery withMaxFlights(int flights) {
        return new QueryByFlights(flights);
    }
}
