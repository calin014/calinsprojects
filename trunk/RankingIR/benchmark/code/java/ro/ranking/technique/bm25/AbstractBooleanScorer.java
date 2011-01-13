package ro.ranking.technique.bm25;

/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import java.io.IOException;

import org.apache.lucene.search.Scorer;
import org.apache.lucene.search.Similarity;

/**
 * An abstract master class for BM25 Boolean Scorers.
 * Holds an array of subScorers and another indicating which scorer has a next document.
 */
public abstract class AbstractBooleanScorer extends Scorer {

	protected Scorer[] subScorer;
	protected boolean subScorerNext[];

	protected AbstractBooleanScorer(Similarity similarity, Scorer scorer[])
			throws IOException {
		super(similarity);
		this.subScorer = scorer;
		if (scorer != null && scorer.length > 0)
			this.subScorerNext = new boolean[this.subScorer.length];
	}
}