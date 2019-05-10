package org.elsys.tuesky.impl.queries;

import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.impl.TripImpl;

public class QueryByMiddlePoint extends TripQueryImpl {
    private final String middlePoint;

    public QueryByMiddlePoint(String middlePoint) {
        this.middlePoint = middlePoint;
    }

    @Override
    public boolean matches(Trip trip) {
        // TODO Add it to interface
        assert(trip instanceof TripImpl);

        return ((TripImpl)trip).getMiddlePoints()
                .contains(middlePoint);
    }
}
